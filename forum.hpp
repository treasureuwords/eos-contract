#pragma once

#include <eosiolib/eosio.hpp>

#include <string>

namespace eosiosystem {
   class system_contract;
}



using std::string;

class forum : public eosio::contract {
    using contract::contract;
    public:
    struct author {
        account_name     name;
        string           nickname;
        string           photo;
        uint64_t         honor_score;
        string           brief_intro; 

        account_name primary_key() const {return name;}
    };

    struct content {
        uint64_t         id;
        account_name     author;
        string           body;

        uint64_t primary_key() const {return id;};
    };

    struct appraisable {
        uint64_t         like_cnt;
        uint64_t         dislike_cnt;
    };

    struct category {
        string          name;
        string          intro;
        string          rule;
        uint64_t        post_cnt;

        string primary_key() const {return name;};
    };

    struct post : public content , public appraisable {
        string           title;
        uint64_t         attention_degree;
        category         cate;
    };

    struct comment : public post , public appraisable {
        uint64_t         parent_id;
    };

    struct message : public content {
        account_name     to;
        string         title;
    };
    //TODO deal with vote
    struct votable {
    };
    
    public:
    forum( account_name self ):contract(self){}

    void sign_up( account_name account, string nickname, string photo, string brief_intro);

    void create_post( account_name account, string title, string body, string category);

    void create_comment( account_name account, uint64_t parent, string body);

    void like (account_name account, uint64_t id);

    void dislike (account_name account, uint64_t id);

    private:
    typedef eosio::multi_index<N(author), author> users;
    typedef eosio::multi_index<N(post), post> posts;
    typedef eosio::multi_index<N(comment), comment> comments;
        
};

  
 /// namespace formu

EOSIO_ABI(forum, (sign_up)(create_post)(create_comment)(like)(dislike))
