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

template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v){
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++){
        if(!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v){
    bool first = true;
    os << "[";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
        if(!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
        if(!first)
            os << ", ";
        os << *ii ;
        first = false;
    }
    return os << "]";
}
