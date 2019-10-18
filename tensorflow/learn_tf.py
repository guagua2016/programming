import tensorflow as tf
import time

print(tf.__version__)
print(tf.__path__)

a = tf.random_normal([1,255,255,3],dtype=tf.float32,name="a")
b = tf.random_normal([11,11,3,1],dtype=tf.float32,name="b")
print(a,b)


a = tf.constant([1.0,2.0])
b = tf.constant([2.0,3.0])
result = a + b

print(result)

# result = tf.nn.convolution(a,b,padding='VALID')
with tf.Session() as sess:
	start = time.time()
	# tf.initialize_all_variables().run()
	tf.global_variables_initializer().run()
	sess.run(result)
	print(time.time()-start)