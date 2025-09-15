ll sumDigitsUpto(ll n) {
  if (n <= 0)
    return 0;
  ll res = 0, p = 1;
  while (p <= n) {
    ll left = n / (p * 10); // higher part (digits left of current position)
    ll cur = (n / p) % 10;  // current digit at position p
    ll right = n % p;       // lower part (digits right of current position)

    res += left * 45 * p; // contribution of all full cycles
    res += (cur * (cur - 1) / 2) *
           p; // contribution of partial cycle from 0..cur-1
    res += cur *
           (right +
            1); // contribution from the remaining part for the  current digit
    p *= 10;
  }
  return res;
}

/* explanation for the different terms in the calculation

Term 1 → left * 45 * p = 1 * 45 * 1 = 45

👉 This is the contribution of complete cycles of digits 0–9 in the ones place.
From 0..9, the ones digit goes: 0,1,2,3,4,5,6,7,8,9.
Their sum is 45. That’s exactly Term 1.

Term 2 → (cur * (cur-1)/2) * p = (2*1/2)*1 = 1

👉 This counts the “next partial cycle” before reaching the current digit 2.
At number 10, the ones digit = 0 → we’ve completed digit 0 at this place.
At number 11, the ones digit = 1 → we’ve completed digit 1.
So we added 0+1 = 1. That’s Term 2.

Term 3 → cur * (right+1) = 2*(0+1) = 2

👉 Now we count the current digit (2) itself at the ones place, which appears
for the last (right+1) numbers. Here, right=0, so only for 1 number → number 12
has ones digit 2. Contribution = 2. That’s Term 3.

*/
