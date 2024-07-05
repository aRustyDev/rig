/* Holds information about a particular option */
struct option_data {
  /* The character to activate this option. */
  char option;
  /* Does this option take an operand? */
  enum operand_t {ALWAYS, NEVER, OPTIONAL};
  operand_t operand;
  /* Function to call with the operand.
   * First argument option, second operand (or NULL). */
  void (*handler) (char, const char*);

  static void parse_options(int, const char* const[],
                            int, const option_data*);
};

void option_data::parse_options(int argc, const char* const argv[],
                                int numopts,
                                const option_data config[]) {
  for (int i = 1; i < argc; i ++) {
    const char* cp = argv[i];
    if (*cp != '-')
    cp ++;
    do {
      int j;
      for (j = 0; j < numopts; j ++) {
        if (*cp == config[j].option) {
          const char* operand = NULL;
          if (config[j].operand != NEVER) {
            if (*(cp+1) != '\0') {
              operand = cp+1;
              cp = NULL;
            } else if (i + 1 < argc && argv[i+1][0] != '-') {
              i ++;
              operand = argv[i];
              cp = NULL;
            }
          }
          switch (config[j].operand) {
          case ALWAYS:
            if (operand == NULL)
            else
              (*(config[j].handler))(config[j].option, operand);
            break;
          case NEVER:
          case OPTIONAL:
            (*(config[j].handler))(config[j].option, operand);
            break;
          }
          break;
        }
      }
      if (j == numopts)
      if (cp != NULL && *cp != '\0')
        cp ++;
    } while (cp != NULL && *cp != '\0');
  }
}

string locdataidx;
long int numids;
bool male, female;

void set_datadir(char option, const char* dir) {
  assert(option == 'd');
  locdataidx = dir;
}

void set_number(char option, const char* num) {
  assert(option == 'c');
  char * tail;
  numids = strtol(num, &tail, 0);
  
  if (errno || tail == num) {
  }
  // Check that there was no extra stuff in the argument.
  while (*tail != '\0') {
    if (!(*tail == ' ' || *tail == '\t' || *tail == '\n'))
    tail ++;
  }
}

void set_gender(char option, const char* arg) {
  assert((option == 'm' || option == 'f') && arg == NULL);
  if (option == 'm') {
    male = true;
  } else if (option == 'f') {
    female = true;
  }
}

const option_data option_list[] = {{ 'd', option_data::ALWAYS, set_datadir },
                                   { 'c', option_data::ALWAYS, set_number },
                                   { 'f', option_data::NEVER,  set_gender },
                                   { 'm', option_data::NEVER,  set_gender }};
