const gT = (m, n, memo = {}) => {
  const key = m + ',' + n;
  if (key in memo) return memo[key];
  if (m === 1 && n === 1) return 1;
  if (m === 0 || n === 0) return 0;

  memo[key] = gT(m - 1, n, memo) + gT(m, n - 1, memo);
  return memo[key];
};