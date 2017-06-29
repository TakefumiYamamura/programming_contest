import java.util.Scanner;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.Iterator;

public class abc61c {
	public static void main(String[] args) {
		BigArray bg = new BigArray();
		bg.exec();
	}
}

class BigArray {
	static long n;
	static long k;
	static TreeMap<Long, Long> map = new TreeMap<Long, Long>();

	public BigArray() {
		Scanner cin = new Scanner(System.in);
		this.n = cin.nextLong();
		this.k = cin.nextLong();
		for (int i = 0; i < n; i++) {
			long a = cin.nextLong();
			long b = cin.nextLong();
			if (map.containsKey(a)) {
				map.put(a, map.get(a) + b);
			} else {
				map.put(a, b);
			}
		}
	}

	void exec(){
		long cur_i = 0;
		for(long key : map.keySet()) {
			cur_i += map.get(key);
			if(cur_i >= k){
				System.out.println(key);
				return;
			}
		}
	}
}
