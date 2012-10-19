    //Debugging Code
    #ifdef DEBUG
        #define debug(args...)            {dbg,args; cerr<<endl;}
    #else
        #define debug(args...)              // Just strip off all debug token
    #endif

    struct debugger{
        template<typename T> debugger& operator , (const T& v){
            cerr<<v<<" ";
            return *this;
        }
    } dbg;

