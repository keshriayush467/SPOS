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
//  javac MathJNI.java

// Generate C header file 
// javac -h . MathJNI.java

// Compiler the course file with shared lib 
 //  gcc -shared -fPIC -I/usr/lib/jvm/java-17-openjdk-amd64/include \
// -I/usr/lib/jvm/java-17-openjdk-amd64/include/linux \
// -o libmymath.so MathDLL.c


// Run java program
// java -Djava.library.path=. MathDLL




