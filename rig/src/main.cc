int main(int argc, char *argv[])
{
  string streetidx, mnamesidx, fnamesidx, lnamesidx;
  male = female = false;
  numids = 1;
  locdataidx = DATADIR;

  // four options
  option_data::parse_options(argc, argv, 4, option_list);  

  if (!female && !male)
    female = male = true;

  streetidx = locdataidx + "/street.idx";
  mnamesidx = locdataidx + "/mnames.idx";
  fnamesidx = locdataidx + "/fnames.idx";
  lnamesidx = locdataidx + "/lnames.idx";
  locdataidx += "/locdata.idx";
    
  vector<string> firstname, lastname;
  vector<wholeline> street;
  vector<place> location;
  if (readfile(location, locdataidx.c_str()) == 0)
    printfileerror(locdataidx);
  if (readfile(street, streetidx.c_str()) == 0)
    printfileerror(streetidx);
  if (male) {
      if (readfile(firstname, mnamesidx.c_str()) == 0)
          printfileerror(streetidx);
  }
  if (female) {
    if (readfile(firstname, fnamesidx.c_str()) == 0)
      printfileerror(fnamesidx);
  }
  if (readfile(lastname, lnamesidx.c_str()) == 0)
    printfileerror(lnamesidx);
  
  for (int i = 1; i <= numids; i ++) {
    cout << getrandpart(firstname) << " " << getrandpart(lastname) << endl
	 << getrandnum(1024u) + 1 << " " << getrandpart(street) << endl
	 << getrandpart(location) << endl;
    if (i != numids)
      cout << endl;
  }
}