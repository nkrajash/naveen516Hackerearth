class TestClass {
public static void main(String args[] ) throws Exception {
try(BufferedReader in = new BufferedReader(new InputStreamReader(System.in))){
int n = Integer.parseInt(in.readLine());
int arr[] = new int[n];
for(int i=0; i<arr.length; i++)
arr[i] = Integer.parseInt(in.readLine());
for(int i=0,seat_no = 0; i<arr.length; i++){
if(arr[i]%12 == 0)
seat_no = 12*(arr[i]/12 - 1);
else
seat_no = 12*(arr[i]/12);
seat_no += (seat_no + 12) - arr[i] + 1;
System.out.print(seat_no);
if((arr[i]%6 == 0) || (arr[i]%6 == 1))
System.out.println(" WS");
else if((arr[i]%6 == 2) || (arr[i]%6 == 5))
System.out.println(" MS");
else
System.out.println(" AS");
}
}
}
}
