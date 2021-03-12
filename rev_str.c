int rev_core(char *head, int idx) {
  if (head[idx] != '\0') {
    int end = rev_core(head, idx + 1);
    if (idx > end / 2)
      swap(head + idx, head + end - idx);
    return end;
  }
  return idx - 1;
}

char *reverse(char *s) {
  rev_core(s, 0);
  return s;
}

int main(int argc, void **argv) {
  char *s = "aba";
  reverse(s);
}