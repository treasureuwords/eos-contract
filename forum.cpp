#include "forum.hpp"


void forum::sign_up( account_name account, string nickname, string photo, string brief_intro)
{
    users usertable( _self, _self );
    auto existing = usertable.find( account );
    if ( existing == usertable.end()){
        usertable.emplace( _self, [&]( auto& u ) {
            u.name = account;
            u.nickname = nickname;
            u.photo = photo;
            u.brief_intro = brief_intro;
            u.honor_score = 0;
        });
    }else{
        usertable.modify(existing, _self, [&]( auto& u){            
            u.nickname = nickname;
            u.photo = photo;
            u.brief_intro = brief_intro;
            u.honor_score = 0;
        })
    }    
}


void forum::create_post( account_name account, string title, string body, string category){
    print("post [", body, "] from ", name)
}

void forum::create_comment( account_name account, uint64_t parent, string body){
    print("comment [", body, "] from ", name)
}

void forum::like (account_name account, uint64_t id){
    print("like [", id, "] from ", name)
}

void forum::dislike (account_name account, uint64_t id){
    print("dislike [", ik, "] from ", name)
}


EOSIO_ABI(forum, (sign_up)(create_post)(create_comment)(like)(dislike))