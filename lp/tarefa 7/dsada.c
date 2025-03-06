int main() {
    int n=0,k,maiornum=0;
    int v1[n];
  scanf("%d",&n);

  for (k=0;k < n;k++){
    scanf("%d",&v1[k]);
    if (v1[k]>maiornum){
      maiornum=v1[k];
    }
  }
  printf("%d",maiornum);
  return 0;
}
