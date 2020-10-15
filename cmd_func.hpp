map<string,val>value;

string convertToPrint(string test){
    for(int i=0;i<test.length();i++){
        if(test[i]=='+'){
            return convertToPrint(test.substr(0,i))+convertToPrint(test.substr(i+1,test.length()-1));
        }
    }
    try{
        stoi(test);
        return test;
    }
    catch(const invalid_argument&){
        if(test[0]=='"' && test[test.length()-1]=='"'){
            test.erase(test.begin());
            test.erase(test.end()-1);
            return test;
        }
        else if(value.find(test)!=value.end()){
            return value[test].toString();
        }
        else return message("there is something error in: "+test,false),"";
    }
}

void runCmd(string cmd){

    if(cmd=="intro")intro();

    else if(cmd.substr(0,6)=="print(" && cmd.substr(cmd.length()-1)==")"){
        string v=cmd.substr(6,cmd.length()-7);
        cout<<convertToPrint(v)<<endl;
    }

    else if(cmd.find("=")!=cmd.npos){
        string v=cmd.substr(0,cmd.find("="));
        string temp=cmd.substr(cmd.find("=")+1,cmd.length());
        if(value.find(temp)!=value.end()){
                value[v]=value[temp];
        }
        else value[v].set(temp);
    }

    else if(cmd.substr(0,6)=="input(" && cmd.substr(cmd.length()-1)==")"){
        string v=cmd.substr(6,cmd.length()-7);
        string temp;
        cout<<v<<"=";
        cin>>temp;
        value[v].set(temp,false);
        cin.get();
    }

    else if(cmd.substr(0,7)=="delete(" && cmd.substr(cmd.length()-1)==")"){
        string v=cmd.substr(7,cmd.length()-8);
        if(value.find(v)!=value.end())value.erase(value.find(v));
        else message("there is no this varible: "+v);
    }
    else if(cmd.substr(0,5)=="type(" && cmd.substr(cmd.length()-1)==")"){
        string v=cmd.substr(5,cmd.length()-6);
        if(value.find(v)!=value.end())message(value[v].type());
        else message("there is no this varible: "+v);
    }

    else if(cmd=="list"){
        if(value.empty()){
            message(R"(here is the list of your variable:
        empty.)");
        }
        else{
            message("here is the list of your variable:",false);
            for(map<string,val>::iterator i=value.begin();i!=value.end();i++){
                cout<<"        "<<(i->first);
                cout<<"<"<<i->second.type()<<">:"<<i->second.toString()<<endl;
            }
            cout<<endl;
        }
    }
    else if(cmd=="exit"){message("bye~");exit(0);}
    else if(cmd=="help"){message("nope, try it yourself.");}
    else system(cmd.c_str());
    return;
}
