int countFactor(int x)
{
   int cnt = 0;
   while(x%2 == 0) 
   { 
     cnt++;
     x = x / 2; 
   } 
   
   for(int i = 3; i <= sqrt(x); i += 2)
   {
      while(x%i == 0)
      {
        cnt++;
        x /= i;
      }
   }
   
   if(x > 1) cnt++;
   return cnt;
}

int main()
{
  int n;
  cin >> n;
  countFactor(n);

  return 0;	
}