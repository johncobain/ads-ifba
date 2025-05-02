public class Main{
  public static void main(String[] args) {
    Student[] students = new Student[5];
    Teacher[] teachers = new Teacher[5];

    String choice = "0";

    while(!"q".equals(choice)){
      System.out.println("What would you like to do?");
      System.out.println("1. Add a student");
      System.out.println("2. Display all students");
      System.out.println("3. Add a teacher");
      System.out.println("4. Display all teachers");
      System.out.println("q. Quit");
      choice = System.console().readLine();

      System.out.print("\033[H\033[2J");
      if(null == choice){
        System.out.println("Invalid choice. Please try again.");
      }else switch (choice) {
        case "1" -> {
          for(int i = 0; i < students.length; i++){
            if(students[i] == null){
              students[i] = new Student(System.console().readLine("Enter the name: "));
              students[i].setAge( Integer.parseInt(System.console().readLine("Enter the age: ")));
              students[i].setAddress(System.console().readLine("Enter the address: ")); 
              System.out.print("\033[H\033[2J");
              break;
            }
              if(i == students.length - 1 && students[i] != null){
                System.out.println("No more space to add students.");
              }
            }
          }
          case "2" -> {
            System.out.println("ID\t\tName\t\tAge\t\tAddress");
            System.out.println("-------------------------------------------------------");
            for(Student student : students){
              if(student != null){
                student.display();
              }
            }
            System.out.println();
          }
          case "3" -> {
            for(int i = 0; i < teachers.length; i++){
              if(teachers[i] == null){
                teachers[i] = new Teacher(System.console().readLine("Enter the name: "));
                teachers[i].setAge(Integer.parseInt(System.console().readLine("Enter the age: ")));
                teachers[i].setAddress(System.console().readLine("Enter the address: "));
                teachers[i].setSubject(System.console().readLine("Enter the subject: "));
                teachers[i].setYearsOfExperience(Integer.parseInt(System.console().readLine("Enter years of experience: ")));
                System.out.print("\033[H\033[2J");
                break;
              }
              if(i == teachers.length - 1 && teachers[i] != null){
                System.out.println("No more space to add teachers.");
              }
            }
          }
          case "4" -> {
            System.out.println("ID\t\tName\t\tAge\t\tAddress\t\tSubject\t\tYears of Experience");
            System.out.println("---------------------------------------------------------------------------------------------------------");
            
            for(Teacher teacher : teachers){
              if(teacher != null){
                teacher.display();
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