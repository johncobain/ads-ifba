

class Student{
  private String name;
  private int age;
  private String address;
  private final int id;

  private static int studentCount;

  public Student(){
    id = studentCount++;
  }

  public void haveBirthday(){
    age++;
  }

  public void display(){
    System.out.println(id + "\t|\t" + name + "\t|\t" + age + "\t|\t" + address);
    System.out.println("-----------------------------------------------------");
  }

  public static void main(String[] args) {
    Student[] students = new Student[5];

    String choice = "0";

    while(!"q".equals(choice)){
      System.out.println("What would you like to do?");
      System.out.println("1. Add a student");
      System.out.println("2. Display all students");
      System.out.println("q. Quit");
      choice = System.console().readLine();

      System.out.print("\033[H\033[2J");
      if(null == choice){
        System.out.println("Invalid choice. Please try again.");
      }else switch (choice) {
        case "1" -> {
          for(int i = 0; i < students.length; i++){
            if(students[i] == null){
              students[i] = new Student();
              students[i].name = System.console().readLine("Enter the name: ");
              students[i].age = Integer.parseInt(System.console().readLine("Enter the age: "));
              students[i].address = System.console().readLine("Enter the address: ");
              System.out.print("\033[H\033[2J");
              break;
            }
              if(i == students.length - 1 && students[i] != null){
                System.out.println("No more space to add students.");
              }
            }
          }
          case "2" -> {
            System.out.println("ID\tName\tAge\tAddress");
            System.out.println("-------------------------------------");
            for(Student student : students){
              if(student != null){
                student.display();
              }
            }
            System.out.println();
          }
          case "q" -> System.out.println("Exiting...");
          default -> System.out.println("Invalid choice. Please try again.");
        }
    }
  }
}