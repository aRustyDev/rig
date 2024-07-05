
template <class T>
T getrandnum(T max)
{
  static ifstream urandev("/dev/urandom");
  T rval;
  if (urandev) {
    /* /dev/urandom works. */
    urandev.read((char*)&rval, sizeof(rval));
  } else {
/* this ifdef is messy but does the right thing - we only try /dev/random
 * if it is defined. */
#ifdef DEVRANDOM
    static ifstream randev("/dev/random");
    if (randev) {
      /* /dev/random works. */
      randev.read(&rval, sizeof(rval));
    } else
#endif
    {      
      /* neither /dev/random nor /dev/urandom work; fallback to rand(). */
      static bool seeded = false;
      if (!seeded) {
	srand(time(NULL) ^ (((unsigned int) getpid()) << 15));
	seeded = true;
      }
      unsigned int written = 0;
      char* buf = (char*)(void*)(&rval);
      while (written < sizeof(rval)) {
	int tmp = rand();
	unsigned int bytestocopy = sizeof(rval) - written;
	if (bytestocopy > sizeof(int)) {
	  bytestocopy = sizeof(int);
	}
	memcpy(buf+written, &tmp, bytestocopy);
	written += bytestocopy;
      }
    }
  }
  if (max == 0)
    return max;
  else
    return rval % max;
}

template <class T>
typename T::value_type getrandpart(T& a)
{
  return a[getrandnum(a.size() - 1)];
}
