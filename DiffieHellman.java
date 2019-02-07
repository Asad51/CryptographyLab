import java.math.BigInteger; 
import java.util.Scanner; 
import java.util.Random;

class DiffieHellman
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

	    System.out.println("Enter prime number (p) : ");
	 	BigInteger p = sc.nextBigInteger();

	 	System.out.println("Enter primitive root of " + p + " : ");
	 	BigInteger g = sc.nextBigInteger();

	 	System.out.println("Choose 1st secret (Alice) : ");
	 	BigInteger a = sc.nextBigInteger();

	 	System.out.println("Choose 2nd secret (BOB) : ");
	 	BigInteger b = sc.nextBigInteger();
	 
	 	BigInteger A = g.modPow(a, p);
	 	BigInteger B = g.modPow(b, p);
	 
	 	BigInteger S_A = B.modPow(a, p);
	 	BigInteger S_B = A.modPow(b, p);

	 	if(S_A.compareTo(S_B) == 0)
	 	{
	 		System.out.println("ALice and Bob can communicate with each other!!!");
	 		System.out.println("They share a secret : " + S_A); 
	 	}
	 	else
	 	{
	 		System.out.println("ALice and Bob cannot communicate with each other!!!");
	 	}
	} 
}
