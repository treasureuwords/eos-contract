#pragma once

#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>

#include <string>

namespace eosiosystem {
   class system_contract;
}

namespace forum {

   using std::string;

   struct author {
       account_name     name;
       string           nickname;
       string           photo;
       uint64_t         honor_score;
       string           brief_intro; 
   }
   struct content {
       uint64_t         id;
       account_name     author;
       string           body;
   }
   struct appraisable {
       uint64_t         like_cnt;
       uint64_t         dislike_cnt;
   }
   struct category {
       string name;
   }

   struct post : public message : public appraisable {
       string           title;
       uint64_t         attention_degree;
       category         cate;
   }
   struct comment : public post : public appraisable {
       uint64_t         parent_id;
   }
   struct message : public content {
       account_name     to;
       string         title;
   }
   struct votable {
   }


   class forum : public contract {
      public:
         forum( account_name self ):contract(self){}

         void create_post( post p);

         void create_comment( comment c );

         
   };

  

} /// namespace formu
