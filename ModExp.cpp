typedef long long LL;
// calculate  araised to power b mod M

LL modExp(LL a, LL b, LL mod){
  if(0==b) return 1;
  LL z = modExp(a,b/2,M);
  if(b&1){
    return (z*z)%M;
  }
  return (a*z*z)%M;
}