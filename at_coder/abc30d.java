import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;

class Node{

    int value;
    int parent;

    public Node(int value, int parent){
        this.value = value;
        this.parent = parent;
    }
}


public class abc30d {
    public static void main(String[] args) {
        StragneDictionary sd = new StragneDictionary();
        sd.exec();
    }
}



class StragneDictionary {
    
    int N;
    int A;
    BigInteger K;
    Node[] board;
    int startLoopPoint;
    int startLoopPointCount;
    int loopLength;
    
    public StragneDictionary() {
        Scanner cin = new Scanner(System.in);
        this.N = cin.nextInt();
        this.A = cin.nextInt() - 1;
        this.K = new BigInteger(cin.next());

        this.board = new Node[N];
        for (int i = 0; i < N ; i++) {
            board[i] = new Node(i, cin.nextInt() - 1);    
        }

    }
    
    void exec() {
        findLoop();

        int ans = this.A;

        if(K.compareTo( BigInteger.valueOf(startLoopPointCount) )  > 0) {
            K = K.subtract(BigInteger.valueOf(startLoopPointCount));
            K = K.remainder(BigInteger.valueOf(loopLength) );
            ans = startLoopPoint;
        }
        int sK =  K.intValue();

        for (int i = 0; i < sK ; ++i) {
            ans = board[ans].parent;
        }

        System.out.println(ans + 1);
    }

    void findLoop(){
        int count = 0;
        int cur = this.A;

        int hashTable[] = new int [100001];
        Arrays.fill(hashTable, -1);
        hashTable[cur] = 0;

        while(true){
            count++;
            cur = board[cur].parent;
            if(hashTable[cur] != -1) break;
            hashTable[cur] = count;
        }
        this.loopLength = count - hashTable[cur];
        this.startLoopPointCount = hashTable[cur];
        this.startLoopPoint = cur;
    }
    
}
