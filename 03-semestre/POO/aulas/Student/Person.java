class Person{
  private String name;
  private int age;
  private String address;
  private int id;

  public Person(String name){
    this.name = name;
  }

  public void setName(String name) {
    this.name = name;
  }
  public String getName() {
    return name;
  }
  public void setAge(int age) {
    this.age = age;
  }
  public int getAge() {
    return age;
  }
  public void setAddress(String address) {
    this.address = address;
  }
  public String getAddress() {
    return address;
  }
  public int getId() {
    return id;
  }
  public void setId(int id) {
    this.id = id;
  }
  public void display() {
    System.out.println(id + "\t|\t" + name + "\t|\t" + age + "\t|\t" + address);
    System.out.println("-----------------------------------------------------");
  }
}