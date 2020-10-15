class val{

private:

    string _type;

    string _s;
    int _i;


public:
    val(string s="",bool quo=true){
        try{
            _i=stoi(s);
            _type="int";
        }
        catch(const invalid_argument&){
            if(s[0]=='"' && s[s.length()-1]=='"'){
                s.erase(s.begin());
                s.erase(s.end()-1);
            }
            _s=s;
            _type="string";
        }
    }
    void set(val a){
        _s=a._s;
        _i=a._i;
        _type=a._type;
    }
    bool set(string s,bool quo=true){
        try{
            _i=stoi(s);
            _type="int";
        }
        catch(const invalid_argument&){
            if(s[0]=='"' && s[s.length()-1]=='"'){
                s.erase(s.begin());
                s.erase(s.end()-1);
            }
            else if(quo){
                message("error while setting value");
                return false;
            }
            _s=s;
            _type="string";
        }
        return true;
    }
    string type(){return _type;}
    string toString(){
         if(_type=="string")return _s;
         else  if(_type=="int")return to_string(_i);
         return "";
    }
    val cmd(char cmd,val a){
        if(cmd=='+'){
            val c(_s+a._s,_i+a._i);
            return c;
        }
    }
};
