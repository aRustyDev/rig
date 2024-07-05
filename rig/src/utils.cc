/* Returns number of records gotten. */
template <class T>
int readfile(T& dest, const char * origin)
{
  int counter = 0;
  ifstream filetoread(origin);
  while (filetoread) {
    typename T::value_type temp;
    filetoread >> temp;
    dest.push_back(temp);
    counter++;
  }
  return counter;
}
