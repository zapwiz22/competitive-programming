// cp-algorithms minimum stack and minimum queue

// queue functions
void add(deque<ll> &dq, ll val) {
  while (!dq.empty() and dq.back() > val) {
    dq.pop_back();
  }
  dq.push_back(val);
}

void remove(deque<ll> &dq, ll toRemove) {
  if (!dq.empty() and dq.front() == toRemove) {
    dq.pop_front();
  }
}

ll minimum(deque<ll> &dq) { return dq.front(); }
