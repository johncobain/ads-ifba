class Student extends Person{ 

  private static int studentCount;

  public Student(){
    setId(studentCount++);
  }

  public void haveBirthday(){
    setAge(getAge() + 1);
  }

  @Override
  public void display(){
    System.out.println(getId() + "\t|\t" + getName() + "\t|\t" + getAge() + "\t|\t" + getAddress());
    System.out.println("-----------------------------------------------------");
  }
}