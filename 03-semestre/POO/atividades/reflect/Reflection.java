import java.lang.reflect.Method;

public class Reflection{
  public static void main(String[] args) {
    Class<?> clazz = Test.class;

    Method[] methods = clazz.getDeclaredMethods();

    for(Method method : methods) {
      System.out.println("---------------------------");
      System.out.println("Method Name: " + method.getName());
      System.out.println("Return Type: " + method.getReturnType().getName());
      System.out.println("Modifiers: " + java.lang.reflect.Modifier.toString(method.getModifiers()));
      System.out.println("Parameters: " + java.util.Arrays.toString(method.getParameterTypes()));
      System.out.println("---------------------------");
    }
    
  }
}

class Test {
  public void publicM(int i){}
  private void privateM(String s){}
  protected void protectedM(double d){}
  void packagePrivateM(long l){}
}