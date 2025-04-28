class Teacher extends Person {
  private String subject;
  private int yearsOfExperience;

  private static int teacherCount;

  public Teacher() {
    setId(teacherCount++);
  }
  public void setSubject(String subject) {
    this.subject = subject;
  }
  public String getSubject() {
    return subject;
  }
  public void setYearsOfExperience(int yearsOfExperience) {
    this.yearsOfExperience = yearsOfExperience;
  }
  public int getYearsOfExperience() {
    return yearsOfExperience;
  }

  @Override
  public void display() {
    System.out.println(getId() + "\t|\t" + getName() + "\t|\t" + getAge() + "\t|\t" + getAddress() + "\t|\t" + subject + "\t|\t" + yearsOfExperience);
    System.out.println("---------------------------------------------------------------------------------------------------------");
  }
}