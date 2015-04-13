
#include "ald_font.h"
#include <ctype.h>


cAldFont::cAldFont(const string& path) :
m_font(path),
m_pos(float2::Zero()),
m_count(0),
m_current_count(0),
m_aligned_count(0)
{
  m_rand_alpha = "A""B""C""D""E""F""G"
                 "H""I""J""K""L""M""N"
                 "O""P""Q""R""S""T""U"
                 "V""W""X""Y""Z";
  m_rand_punct = "!""#""$""%""&""'""("
                 ")""*""+"",""-"" ""/"
                 ":"";""<""="">""?""@"
                 "^""_""`""{""|""}""~"
                 ")";
}


void cAldFont::draw(const string& text, const float2& pos,
                    const float&  time, const Color&  color) {
  m_characters = text.size();
  m_text.resize(m_characters);
  m_pos = pos;
  m_color = color;

  // 毎ループごとにランダムな文字を入れる
  if (m_current_count < m_characters-1){
    m_count += time;
    m_current_count = int(m_count);

    if (isalpha(text.at(m_current_count))){
      m_text.at(m_current_count) = m_rand_alpha.at(random(0, 25));
    }
    if (ispunct(text.at(m_current_count))){
      m_text.at(m_current_count) = m_rand_punct.at(random(0, 28));
    }

    // ランダム処理が終わって次の文字に進むとき
    // 受け取った文字を入れる
    // ここで文字が整う
    if (m_aligned_count < m_current_count){
      m_text.at(m_aligned_count) = text.at(m_aligned_count);
      m_aligned_count++;
    }
  }
  
  // 末端の文字を整える
  if (m_aligned_count == m_characters - 1){
    m_text.at(m_aligned_count) = text.at(m_aligned_count);
  }

  // 描画
  m_font.draw(m_text, Vec2f(m_pos.x, m_pos.y), m_color);
}

void cAldFont::size(const u_int& size) {
  m_font.size(size);
}