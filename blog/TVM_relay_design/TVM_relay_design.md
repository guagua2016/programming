---
title: TVM学习笔记--Relay的设计和实现
categories:
- other
mathjax: true
---

## References
[1]. Unified IR RFC,https://github.com/apache/incubator-tvm/issues/4617
[2]. Codegen的实现：https://tvm.apache.org/docs/dev/relay_bring_your_own_codegen.html


## 两种Graph-IR
### DAG-based IR
基于DAG（directed acyclic graph)表示的方式是一种传统的计算图表示方式，它的优点比较简单，而且比较成熟，有很多现成的图优化算法。容易实现自动微分，容易在异构环境下编译。缺点是没有定义计算的范围，会造成语意模糊；另外缺少控制流会导致限制其表现能力。
什么是语义模型，当DAG中存在共享的节点时会出现语义模糊的问题。
### Let-binding-based IR 能够通过定义计算范围解决了着这种语义模糊的问题，具有更强的表达能力。两种表示方法语义相同但是AST通常是不同的，这会导致在写pass方法时会有一些不同，

symbolic shape inference
polymorphic functions
control flow


## 如何实现一种graph-IR
1. data和operation的管理
1.1 placeholder
1.2 unknown shape representation. Any or None
1.3 data layout

2. operators supported
2.1. algebraic operators(+,x,exp and topk)
2.2. neural network operator(convolution and pooling)
2.3. tensor operator(reshape,resize and copy)
2.4. broadcast and reduction operators(min and argmin,broadcasting)
2.5. control flow operators (conditional and loop,if,)
2.6. customized operators.


## relay
1. statically typed ? 直接部署在设备上面
2. purely functional
3. differentiable. （





## 代码生成的接口 

　　TVM代码生成的接口和主要类型，可以总结为两个build，两个module，两个function。它提供了两个代码生成的接口，tvm.build和tvm.relay.build，前者是针对算子的代码生成，后者是针对relay计算图的代码生成。在0.7版本中，tvm进行了IR的统一，使得两个build的输入参数类型都可以是IRModule，输出类型都是运行时Module。尽管两个build接口统一了输入类型，但是内部包含的函数类型是不一样的，算子编译时是tvm.tir.function.PrimFunc，而relay图编译时函数类型是tvm.relay.function.Function。TVM在设计时提供了方便的调试功能，通过IRModule的astext函数可以查看ir中间描述，通过运行时module的get_source查看生成的代码。下面通过两个简单的例子查看算子和relay图的ir中间描述和以及对应生成的源代码。

- [tvm.build](https://tvm.apache.org/docs/api/python/driver.html?highlight=build#tvm.build)
- [tvm.relay.build](https://tvm.apache.org/docs/api/python/relay/index.html?highlight=build#tvm.relay.build)
- [tvm.ir.module.IRModule](https://tvm.apache.org/docs/api/python/ir.html?highlight=irmodule#tvm.ir.IRModule)
- [tvm.runtime.module.Module](https://tvm.apache.org/docs/api/python/runtime.html?highlight=module#tvm.runtime.Module)
- [tvm.tir.function.PrimFunc](https://tvm.apache.org/docs/api/python/tir.html?highlight=primfunc#tvm.tir.PrimFunc)
- [tvm.relay.function.Function](https://tvm.apache.org/docs/api/python/relay/index.html?highlight=function#tvm.relay.Function)

### 算子编译
   
	import tvm
	from tvm import te

	M = 1024
	K = 1024
	N = 1024
	
	# Algorithm
	k = te.reduce_axis((0, K), 'k')
	A = te.placeholder((M, K), name='A')
	B = te.placeholder((K, N), name='B')
	C = te.compute(
	           (M, N),
	           lambda x, y: te.sum(A[x, k] * B[k, y], axis=k),
	           name='C')
	
	# Default schedule
	s = te.create_schedule(C.op)
	ir_m = tvm.lower(s, [A, B, C], simple_mode=True,name='mmult')
	rt_m = tvm.build(ir_m, [A, B, C], target='c', name='mmult')
	
	# print tir
	print("tir:\n", ir_m.astext(show_meta_data=False))
	# print source code
	print("source code:\n",rt_m.get_source())

### relay图编译

	import ssl
	ssl._create_default_https_context = ssl._create_unverified_context
	
	from tvm import relay
	from tvm.relay import testing
	from tvm.contrib import util
	import tvm
	
	# Resnet18 workload
	resnet18_mod, resnet18_params = relay.testing.resnet.get_workload(num_layers=18)
	
	with relay.build_config(opt_level=0):
	    _, resnet18_lib, _ = relay.build_module.build(resnet18_mod, "llvm", params=resnet18_params)
	
	# print relay ir
	print(resnet18_mod.astext(show_meta_data=False))
	
	# print source code
	print(resnet18_lib.get_source())


## 代码生成的流程
　　通过上面两个例子我们知道tvm代码生成接口上是IRModule到运行时module的转换，它完成tir或者relay ir到目标target代码的编译，例如c或者llvm IR等。下面的流程图描述整个代码的编译流程，深色表示C++代码，浅色表示python代码。算子编译时会首先进行tir的优化，分离出host和device部分，之后会调用注册的target.build.target函数进行编译。relay图编译相比算子稍微复杂一点，核心代码采用C++开发。它会通过relayBuildModule.Optimize进行relay图优化，之后针对module中的每个lower_funcs进行编译之前，合成最终的运行时module，其后部分的编译流程和算子编译相似。

![TVM代码生成流程](/images/tvm_code_generation.jpg)

##  Codegen的实现
 TVM针对不同的target实现了许多的codgen，它完成了tir到目标代码的翻译工作，例如c,llvm ir等。我们也可以根据需求实现自己的codegen，官网提供了一个[教程](https://tvm.apache.org/docs/dev/relay_bring_your_own_codegen.html)。
- target.build.c
- target.build.llvm
- target.build.cuda
- target.build.opencl
- target.build.opengl
- target.build.metal
- target.build.vulkan


