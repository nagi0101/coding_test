import java.util.Scanner;

class Main {
    public static int N;
    public static int K;
    public static int[] W = new int[101];
    public static int[] V = new int[101];
    public static int[][] AV = new int[101][100001];


    public static int s(int n, int w){
        if(AV[n][w] != -1) return AV[n][w];

        if(n==0) {
            AV[n][w] = w+W[n] <= K ? V[n] : 0;
            return AV[n][w];
        }

        int res0 = s(n-1, w);
        int res1 = w+W[n] <= K ? s(n-1, w+W[n]) + V[n] : -1;

        AV[n][w] = Math.max(res0, res1);

        return AV[n][w];
    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        N=sc.nextInt();
        K=sc.nextInt();

        for(int i=0; i<N; i++){
            W[i]=sc.nextInt();
            V[i]=sc.nextInt();
        }

        for(int i=0; i<AV.length; i++){
            for(int j=0; j<AV[0].length; j++){
                AV[i][j]=-1;
            }
        }

        System.out.println(s(N-1, 0));
    }
}