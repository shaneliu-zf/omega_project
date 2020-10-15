template<typename T>void message(T error_test,bool end=true){
    cout<<endl<<"(´･ω･`):"<<error_test<<endl;
    if(end)cout<<endl;
}

void intro(){
    message(R"(Hello! this is "Omega",
    a interpreted language designed by zhifeng.)");
}
