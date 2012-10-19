#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE (10 * 1024)
struct node_s {
  int next, val;
} nodes[MAX_SIZE];

// Radix-n sort descending. Assumes data are non-negative.
// Will take K passes if largest datum does not exceed n^K.
int sort_descending(struct node_s *nodes, int n)
{
  int i, k, head, next, shifted, digit, more_p, n_passes, div;
  int buckets[MAX_SIZE];

  // Chain nodes into a single list.
  head = 0;
  for (i = 0; i < n; i++)
    nodes[i].next = i + 1;
  nodes[n - 1].next = -1;

  // Make passes until all remainders are zero.
  // Always 2 if max datum is less than n^2.
  n_passes = 0;
  div = 1;
  do {
    // Empty the buckets.
    for (k = 0; k < n; k++)
      buckets[k] = -1;
    // Fill the buckets, noting whether we need more passes.
    more_p = 0;
    for (i = head; i != -1; i = next) {
      next = nodes[i].next;
      shifted = nodes[i].val / div;
      digit = shifted % n;
      nodes[i].next = buckets[digit];
      buckets[digit] = i;
      if (shifted >= div) more_p = 1;
    }
    // Concatenate the buckets.
    head = -1;
    for (k = 0; k < n; k++) {
      for (i = buckets[k]; i != -1; i = next) {
        next = nodes[i].next;
        nodes[i].next = head;
        head = i;
      }
    }
    n_passes++;
    div *= n;
  } while (more_p);
  printf("sort took %d passes\n", n_passes);
  return head;
}

int main(void)
{
  int i, n, head, last;

  n = 500;
  for (i = 0; i < n; i++)
    nodes[i].val = rand() % (n * n);
  head = sort_descending(nodes, n);
  // Make sure we're sorted descending and print.
  last = -1;
  for (i = head; i != -1; i = nodes[i].next) {
    printf("%d ", nodes[i].val);
    if (last != -1 && nodes[i].val > last) {
      printf("oops!\n");
      return 1;
    }
    last = nodes[i].val;
  }
  printf("\n");
  return 0;
}
