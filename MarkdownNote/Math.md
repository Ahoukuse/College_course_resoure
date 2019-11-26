<style>
    .hiden-block{
        background: black;
        color:black;
    }
    .hiden-block:hover{
        color:white;
    }
    ch{
        color:cyan;
    }
    hid{
        background: black;
        color:black;
    }
    hid:hover{
        color:white;
    }
</style>

# Math

## 命题逻辑

__<ch>Q1.命题符号化是什么?</ch>__

就是把命题用数学的逻辑符号表示。命题，就是能判断真假的称述句，被判断为真的命题的真值为真，反之判断为假就是真值为假。  
另外一句称述句是不是命题和它是真是假没关系，重要的是其真值的唯一性。  
同时悖论不是命题。

__<ch>Q2.命题常项，命题变项?</ch>__


__<ch>Q3.基本连接词有那些?</ch>__


__<ch>Q4.等值验算的基本公式都有?</ch>__

$$ a \leftrightarrow b \Leftrightarrow (a \rightarrow b) \wedge (b \rightarrow a.) $$
$$ a \vee (a \wedge b) \Leftrightarrow a $$
$$ a \wedge (a \vee b) \Leftrightarrow a $$
$$ a \rightarrow b \Leftrightarrow {}^{\neg}b \rightarrow {}^{\neg}a $$

__<ch>Q5.范式是什么?</ch>__

范式就是<mark>命题的规范形式</mark>呗，命题公式形式多样，人们规定了特定规则，就形成了范式。<mark>仅由有限个简单合取式</mark>构成的<mark>析取式</mark>称为<mark>析取范式</mark>。<mark>由有限个简单析取式</mark>构成的<mark>合取式</mark>称为<mark>合取范式</mark>

__<ch>Q6.极小项，极大项是什么?</ch>__

若在某个<mark>简单合取式</mark>中<mark>每个</mark>命题变项或其否定都<mark>出先且仅出现一次</mark>，则称其为<mark>极小项</mark>。

若在某个<mark>简单析取式</mark>中<mark>每个</mark>命题变项或其否定都<mark>出先且仅出现一次</mark>，则称其为<mark>极大项</mark>。

当一个<mark>析取范式</mark>全<mark>由极小项构成</mark>是，称其为<mark>主析取范式</mark>  
当一个<mark>合区范式</mark>全<mark>由极大项构成时</mark>，称其为<mark>主合区范式</mark>