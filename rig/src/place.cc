// struct place {
//   string city, state;
//   int ZIP;
//   short int areacode;
// };

ostream& operator<< (ostream& out, const place& a)
{
  out << a.city << ", " << a.state << "  "
      << setfill('0') << setw(5) << a.ZIP << endl
      << "(" << setfill('0') << setw(3) << a.areacode
      << ") xxx-xxxx";
  return out;
}

istream& operator>> (istream& in, place& a)
{
  in >> a.city >> a.state >> a.areacode >> a.ZIP;
  return in;
}
