public class MathJNI {
    public native int add(int a, int b);
    static {
        System.loadLibrary("MathDLL");
    }

    public static void main(String[] args) {
        MathJNI obj = new MathJNI();
        System.out.println("Addition result = " + obj.add(10, 15));
    }
}


// compile Command on ubuntu
//   javac -h . MathJNI.java


// Generates MathJNI.h file