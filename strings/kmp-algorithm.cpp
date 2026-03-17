// KMP Algorithm 
vector<int> kmp(vector<int>& pat) {
  int n = (int)pat.size();
  vector<int> lps(n, 0); // lps[i] => longest prefix which is also suffix for the sub-pattern [0..i]
  lps[0] = 0;
  int i = 1, len = 0;
  while (i < n) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) { // fallback in the pattern 
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}