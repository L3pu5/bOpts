# bOpts
 Command Line Options Handling

 ### By Lepus Hare.

 Parses command line options.

Usage:

    SetOpts(flag, variant[])//Allows for the defining of collapsing multiple opts into 1 opt.
                            // ie: SetOpts("f", {"fix", "fixes", "fi"})
                            // will collapse -f, -fix -fixes -fi into 1 value;

    MakeOpts(argc, argv);   //Allows for the usage of the following commands.

    //All GetOpt variants return a std::string.
    GetOpt();               //Returns argv as a std::string;
    GetOpt("-F");           //Returns a pointer to the string with the -F switch
    GetOpt(n, head=true);   //For a positive integer n and an optional bool 'head':
                            // if head  : return argv[n-1]
                            // else     : return argv[argc-n-1]
                            // ie: GetOpt(0, false) returns the last option. 
    GetFloatingOpt(n);      //Returns the nth opt that is not preceeded directly by a switch.
    GetSwitchOpt(switch);   //Returns the opt following switch.

    FreeOpts();             //Frees any Opt memory, will make Opt commands no longer work.

Logic:
    Loops argv[] and populates a std::map<string>



 Todo:
    Everything.