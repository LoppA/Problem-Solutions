// https://open.kattis.com/problems/aplusb

/*

Combinamos as variacao 1a e 1b do problema da aula

Para contar de quantas formas conseguimos somar valores de uma lista e chegar a um numero

Primeiro transformamos a frequencia dos valores da lista em um polinomio:
Pa = freq[0]*x^2 + freq[1]*x^1 + freq[2]*x^2 + ... + freq[n-1]*x^(n-1)

Pa * Pa nos da de quantas formas conseguimos somar valores da lista chegando a um resultado:
res[i]*x^i -> escolhendo 2 valores da lista conseguimos a soma i de res[i] maneiras distintas

Para a = [1, 2, 3, 4], Pa = 1*x^4 + 1*x^3 + 1*x^2 + 1*x^1 +  0*x^0
Pa * Pa = x^8 + 2*x^7 + 3*x^6 + 4*x^5 + 3*x^4 + 2*x^3 + x^2 + 0*x^1 + 0*x^0

Conseguimos chegar ao resultado 8 de uma forma -> escolhendo 4 duas vezes
Ao 7 de 2 formas -> 3+4 e 4+3
Ao 6 de 3 formas -> 2+4, 4+2 e 3+3

** Precisamos excluir repeticoes **

Para excluir repeticoes, precisamos considera 2 casos:
1. Escolhendo o mesmo valor, ai + ai:
  res[a*2] -= freq[a]
2. Escolhendo (i,j) e (j,i), remover contagens duplas:
  res[a] /= 2

** Precisamos adaptar o resultado para expoentes negativos **

Somamos um valor OFFSET nos valores da lista
Com OFFSET > -min(a), garatimos que a+OFFSET > 0

a += OFFSET

Agora estamos calculado ai + OFFSET + aj + OFFSET = ak
Entao quando estivermos olhando para res[sum] precisamos corrigir o OFFSET

Chegamos a a[k + OFFSET] de res[k + 2*OFFSET] maneiras diferentes
Ou, subtraindo OFFSET
Chegamos a a[k] de res[k + OFFSET] maneiras diferentes


** Precisamos contar o zero de maneira diferente **
Para evitar casos em que a+0=a, 0+a=0 ou 0+0=0
Em vez de excluir contagens duplas que envolvem zero, primeiro excluimos o zero do
polinomio e salvamos a freq[0] para usar depois da multiplicacao de polinomios e
corrigir o resultado

freq[0] = coef(0)
coef(0) = 0

Recontando o zero:

1. ai, aj e ak = 0 e (i,j,k) sao distintos
  ans += freq[0]*(freq[0]-1)*(freq[0]-2)

2. ai + 0 = ak e 0 + aj = ak.
Nesse caso ai = ak e aj = ak respectivamente, mas i!=k e j!=k
  ans += freq[a]*freq[0]*(freq[a]-1) Primeiro caso
  ans += freq[0]*freq[a]*(freq[a]-1) Segundo caso
  Ou apenas: ans += freq[0]*freq[i]*(freq[i]-1)*2;

3. ai + -aj = 0 AND -ai + aj = 0
    ans += freq[a]*freq[-a]*freq[0] // Primeiro caso
    ans += freq[-a]*freq[a]*freq[0] // Segundo caso
    Ou apenas: ans += freq[0]*freq[a]*freq[-a]*2
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

template <typename T>
std::ostream& operator<< (std::ostream& out, const vector<T>& v) {
    out << '[';
    bool f = false;
    for(auto& x:v){
      if (f)  out<<", ";
      f = true;
      out<<x;
    }
    out << "]";
    return out;
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
  vector<string> __attribute__ ((unused)) args,
  __attribute__ ((unused)) int idx,
  __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef DEBUG
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define debug_endl() cout << endl;
#else
#define debug(...) 42
#define debug_endl(...) 42
#endif

typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n=(int) a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit=n>>1;
		for (;j>=bit;bit>>=1)
			j-=bit;
		j+=bit;
		if(i<j)
			swap(a[i],a[j]);
	}
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w(1);
			for (int j=0; j<len/2; ++j) {
				base u=a[i+j], v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if (invert)
		for(int i=0;i<n;++i)
			a[i]/=n;
}

// a, b => coefs to multiply,  res => resulting coefs
// a[0], b[0], res[0] = coef x^0
// Doesnt work with negative coefs
void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n=1;
	while (n<max(a.size(),b.size())) n<<=1;
	n<<=1;
	fa.resize(n),fb.resize(n);
	fft (fa,false);  fft(fb,false);
	for (size_t i=0; i<n; ++i)
		fa[i]*=fb[i];
	fft (fa, true);
	res.resize (n);
	// avoid precision errors, mess up with negative values of coefs
	for(size_t i=0; i<n; ++i) {
		res[i]=ll(fa[i].real() + 0.5);
  }
}

int main (void) {
	ios_base::sync_with_stdio(false);

  const int OFFSET = 51234;
  const int N = 2*OFFSET + 10;
  vector<ll> a(N, 0);

  int n;  cin >> n;
  while(n--) {
    int i;  cin >> i;
    a[i+OFFSET]++;
  }

  ll cnt_zero = a[OFFSET];
  a[OFFSET] = 0;

  vector<ll> res;
  multiply(a, a, res);

  for (int i = 0; i < N; i++) {
    res[2*i] -= a[i];
  }

  ll ans = (cnt_zero)*(cnt_zero-1)*(cnt_zero-2);
  for (int i = 0; i < N; i++) {
    ll dist_k = a[i];
    ll dist_ij = res[i+OFFSET];

    ans += dist_k * dist_ij;
  }

  // zero + a = a AND a + zero = a
  for (int i = 0; i < N; i++) {
    ans += cnt_zero*a[i]*(a[i]-1)*2LL;
  }

  // a + -a = 0 AND -a + a = 0
  for (int i = OFFSET+1; i < N; i++) {
    int val = i - OFFSET;
    ans += cnt_zero*a[val+OFFSET]*a[-val+OFFSET]*2LL;
  }


  cout << ans << endl;

	return 0;
}


