
#pragma once
#include "../common.h"
#include "float2.h"
#include <string>
using namespace std;


class cAldFont {
public:

  // 描画するフォントのpath
  cAldFont(const string&);

  // text  描画する文字列
  // pos   描画する位置
  // time  文字を処理する時間(数値が小さいほど遅い)
  // color 文字の色
  void draw(const string&, const float2&,
            const float&,  const Color&);

  // const u_int& size  フォントのサイズ
  void size(const u_int&);


private:

  Font   m_font;
  string m_text;
  float2 m_pos;
  Color  m_color;
  u_int  m_size;
  float  m_characters;    // 与えられた文字の数を保存

  float  m_count;

  int    m_current_count; // ランダムな文字を入れる際の文字数カウント
  int    m_aligned_count; // 文字を整えるための文字数カウント

  string m_rand_alpha;    // 英文字　群
  string m_rand_punct;    // 　記号　群

  Random random;
};