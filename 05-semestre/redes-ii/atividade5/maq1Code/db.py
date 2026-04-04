import mysql.connector  

class DBConnection(): 
  def __init__(self): 
    self.connection = mysql.connector.connect( 
      host="localhost", 
      user="root", 
      password="root", 
      database="DB" 
    ) 
 
 
  def selectAll(self):
    self.connection.commit()
    cursor = self.connection.cursor() 
    cursor.execute("SELECT * FROM USERS") 
    return cursor.fetchall() 
  
  def insertData(self, data): 
    cursor = self.connection.cursor() 
    sql = "INSERT INTO USERS (name, email) VALUES (%s, %s)" 
    val = (data[0], data[1]) 
    try: 
      cursor.execute(sql, val) 
      self.connection.commit() 
      return cursor.lastrowid 
    except: 
      return False 

  def updateData(self, data): 
    cursor = self.connection.cursor() 
    sql = "UPDATE USERS SET name=%s, email=%s WHERE ID=%s" 
    val = (data[0], data[1], data[2]) 
    try: 
      cursor.execute(sql, val) 
      self.connection.commit() 
      return cursor.rowcount 
    except: 
      return False 

  def deleteData(self, data): 
    cursor = self.connection.cursor() 
    sql = "DELETE FROM USERS WHERE ID=%s" 
    val = (data[0], ) 
    try: 
      cursor.execute(sql, val) 
      self.connection.commit() 
      return cursor.rowcount 
    except: 
     return False 