void mergesort(int *a, int len) {
  int temp, listsize, xsize;

  for (listsize = 1; listsize <= len; listsize*=2) {
    for (int i = 0, j = listsize; (j+listsize) <= len; i += (listsize*2), j += (listsize*2)) {
      merge(& a[i], listsize, listsize);
    }
  }

  listsize /= 2;

  xsize = len % listsize;
  if (xsize > 1)
    mergesort(& a[len-xsize], xsize);

  merge(a, listsize, xsize);
}

void merge(int *a, int sizei, int sizej) {
  int temp;
  int ii = 0;
  int ji = sizei;
  int flength = sizei+sizej;

  for (int f = 0; f < (flength-1); f++) {
    if (sizei == 0 || sizej == 0)
      break;

    if (a[ii] < a[ji]) {
      ii++;
      sizei--;
    }
    else {
      temp = a[ji];

      for (int z = (ji-1); z >= ii; z--)
        a[z+1] = a[z];
      ii++;

      a[f] = temp;

      ji++;
      sizej--;
    }
  }
}

