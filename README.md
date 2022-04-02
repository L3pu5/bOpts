# bOpts
 Command Line Options Handling

 ### By Lepus Hare.

 Parses command line options.

Namespace:
    bOpts


Usage:
    Download and include the "bOpts.h" header file.


    #include "bOpts.h"

    bOpts::SetOpts(flag, variants) //Allows for the defining of collapsing multiple opts into 1 opt.
                            // ie: SetOpts("f", {"fix", "fixes", "fi"})
                            // will collapse -f, -fix -fixes -fi into 1 value;
    bOpts::SetToggleOpts(toggles)  //Allows for 'true' 'false' switches.
                                   //  ie: SetToggleOpts({"X", "Y"})
                                   // will allow -X 
                                   // and will GetToggleOpt("X") -> 1
                                   // GetToggleOpt("Y") -> 0

    bOpts::MakeOpts(argc, argv);   //Allows for the usage of the following commands.

    //All GetOpt variants return a std::string.
    bOpts::GetOpt();               //Returns argv as a std::string;
    bOpts::GetOpt("F");            //Returns the string with the -F switch
    bOpts::GetOpt(n, head=true);   //For a positive integer n and an optional bool 'head':
                            // if head  : return argv[n-1]
                            // else     : return argv[argc-n-1]
                            // ie: GetOpt(0, false) returns the last option.
    bOpts::GetFloatingOpt(n);      //Returns the nth opt that is not preceeded directly by a switch.
    bOpts::GetToggleOpt("X");**    //Returns 0/1,F/T for a switch "X" whether or not it was passed as an arg.
                                   // ** Requires SetToggleOpts({}) to be supplied before MakeOpts();


TODO:
    Consider adding in options for forcing case of both switches and the arguments read.
