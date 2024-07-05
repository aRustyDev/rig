
struct wholeline {
  string name;
};

ostream& operator<< (ostream& out, const wholeline& a)
{
  out << a.name;
  return out;
}

istream& operator>> (istream& in, wholeline& a)
{
  char temp = 'a';
  for (;;) {
    temp = in.get();
    if (temp == '\n' || temp == '\r' || temp == '0' || !in)
      break;
    a.name += temp;
  }
  return in;
}
