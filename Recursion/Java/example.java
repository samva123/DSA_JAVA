class oppo{
	public void camera() {
		System.out.println("Camera working");
	}

}
 class iphone{
	 oppo o ; //
	 iphone(oppo o ){
		 this.o = o;
	 }
	public void airdrop() {
		o.camera();
		System.out.println("Airdrop working");
	}

}
public class example {
	public static void main(String[]args) {
		oppo o = new oppo();
		iphone i = new iphone(o);
		i.airdrop();
	}
}