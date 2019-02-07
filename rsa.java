import java.math.BigInteger; 
import java.util.Scanner; 
import java.util.Random;
import java.io.*;

public class rsa{
	static BigInteger encrypt(BigInteger plainText, BigInteger publicKey, BigInteger modulus) {
      return plainText.modPow(publicKey, modulus);
   	}

   	static BigInteger decrypt(BigInteger cipherText, BigInteger privateKey, BigInteger modulus) {
      return cipherText.modPow(privateKey, modulus);
    }

	public static void main(String[] args) {
		BigInteger one = new BigInteger("1");
		BigInteger zero = new BigInteger("0");
		Scanner sc = new Scanner(System.in);
		//FileInputStream fin = new FileInputStream("input.txt");

		System.out.println("Enter bit length for generating prime numbers : ");
		int bitLength = sc.nextInt();
		Random rnd = new Random();

		BigInteger p = BigInteger.probablePrime(bitLength, rnd);
		BigInteger q = BigInteger.probablePrime(bitLength, rnd);
		BigInteger n = p.multiply(q);

		BigInteger e = BigInteger.probablePrime(bitLength, rnd);
		BigInteger t = (p.subtract(one)).multiply((q.subtract(one)));

		while(e.gcd(t).compareTo(one) != 0){
			e = BigInteger.probablePrime(bitLength, rnd);
		}

		BigInteger d = e.modInverse(t);

		System.out.println("Enter text to encrypt : ");
		String plainText = sc.next();
		String cipherText = "";
		for(int i = 0; i<plainText.length(); i++){
			int ch = (int) plainText.charAt(i);
			cipherText += encrypt(BigInteger.valueOf(ch), e, n).toString(10) + '.';
		}
		
		 String[] encrypted = cipherText.split("\\.");
		 String decryptedText = "";
		 for(int i = 0; i < encrypted.length; i++){
		 	String decrypted = decrypt(new BigInteger(encrypted[i], 10), d, n).toString();
		 	decryptedText += (char) Integer.parseInt(decrypted);
		 }

		System.out.println("Encrypted Text: " + cipherText);
		System.out.println("Decrypted Text: " + decryptedText);
	}
}