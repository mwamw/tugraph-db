为了在Neo4j里测试优化效果，要把使用视图优化后的PatternGraph反向重写为Cypher语句。
比如
```
match (n:Comment)-[r:replyOf*1..]->(m:Post) return n,m
```
这里有两个`replyOf*1..`可以用`ROOT_POST`优化，可以重写为
```
match (n:Comment)-[r:ROOT_POST]->(m:Post) return n,m
```
也是和之前一样用Visitor的方式，在src/cypher/parser/anti_rewrite_visitor.h里遍历语法树，得到新的查询语句，主要更改的应该只有Match子句的部分。

* 函数的输入为
    ```
    cypher::RTContext *ctx
    antlr4::tree::ParseTree *tree,
    const std::vector<cypher::PatternGraph> &pattern_graphs
    ```
    这里的&pattern_graphs是优化后的PatternGraphs，如果需要可以把优化前的PatternGraphs也传进来，在ExecutionPlan类里添加属性保存旧的PatternGraph.
* 输出为优化后的查询语句，测试时在需要优化的Cypher语句前加上Optimize即可，比如在tugraph中输入Cypher语句：`Optimize match (n:Comment)-[r:replyOf*1..]->(m:Post) return n,m`应该返回`match (n:Comment)-[r:ROOT_POST]->(m:Post) return n,m`