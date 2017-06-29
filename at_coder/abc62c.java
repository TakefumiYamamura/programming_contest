import java.util.Scanner;

public class abc62c {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		long h = cin.nextLong();
		long w = cin.nextLong();
		long ans = Math.min(func1(h, w), func2(h, w));
		ans = Math.min(ans, func2(w, h));
		System.out.println(ans);
	}

	public static long func1(long h, long w){
		if(h % 3 == 0 || w % 3 == 0){
			return 0;
		}
		return Math.min(h, w);
	}

	public static long func2(long h, long w){
		long min_dif = h * w ;
		if(w % 2 == 0) {
			for (long i = 1; i < h; ++i ) {
				min_dif = Math.min(Math.abs(w * i - w / 2 * (h - i)), min_dif );	
			}
		} else {
			for (long i = 1; i < h; ++i ) {
				long max_dif = Math.max(Math.abs( (w+1) / 2 * (h - i) - w / 2 * (h - i)) , Math.max(Math.abs(w * i - w / 2 * (h - i)), Math.abs(w * i - (w+1) / 2 * (h - i))));
				min_dif = Math.min(max_dif, min_dif);
			}
		}
		return min_dif;
	}
}