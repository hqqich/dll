public class Hello {

	static {
		System.loadLibrary("hello");
	}

	public static native long add(long x, long y, String z);

	public static void main(String args[]) {
		System.out.println(add(123, 321, "aa"));
	}
}
