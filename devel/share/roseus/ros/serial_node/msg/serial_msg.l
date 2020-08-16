;; Auto-generated. Do not edit!


(when (boundp 'serial_node::serial_msg)
  (if (not (find-package "SERIAL_NODE"))
    (make-package "SERIAL_NODE"))
  (shadow 'serial_msg (find-package "SERIAL_NODE")))
(unless (find-package "SERIAL_NODE::SERIAL_MSG")
  (make-package "SERIAL_NODE::SERIAL_MSG"))

(in-package "ROS")
;;//! \htmlinclude serial_msg.msg.html


(defclass serial_node::serial_msg
  :super ros::object
  :slots (_roll _pitch _yaw _linear_x _linear_y _angular_z ))

(defmethod serial_node::serial_msg
  (:init
   (&key
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    ((:yaw __yaw) 0.0)
    ((:linear_x __linear_x) 0.0)
    ((:linear_y __linear_y) 0.0)
    ((:angular_z __angular_z) 0.0)
    )
   (send-super :init)
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   (setq _yaw (float __yaw))
   (setq _linear_x (float __linear_x))
   (setq _linear_y (float __linear_y))
   (setq _angular_z (float __angular_z))
   self)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:linear_x
   (&optional __linear_x)
   (if __linear_x (setq _linear_x __linear_x)) _linear_x)
  (:linear_y
   (&optional __linear_y)
   (if __linear_y (setq _linear_y __linear_y)) _linear_y)
  (:angular_z
   (&optional __angular_z)
   (if __angular_z (setq _angular_z __angular_z)) _angular_z)
  (:serialization-length
   ()
   (+
    ;; float32 _roll
    4
    ;; float32 _pitch
    4
    ;; float32 _yaw
    4
    ;; float32 _linear_x
    4
    ;; float32 _linear_y
    4
    ;; float32 _angular_z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _linear_x
       (sys::poke _linear_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _linear_y
       (sys::poke _linear_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angular_z
       (sys::poke _angular_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _roll
     (setq _roll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch
     (setq _pitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw
     (setq _yaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _linear_x
     (setq _linear_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _linear_y
     (setq _linear_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angular_z
     (setq _angular_z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get serial_node::serial_msg :md5sum-) "46c11c19de8f979808da3e975b371e2c")
(setf (get serial_node::serial_msg :datatype-) "serial_node/serial_msg")
(setf (get serial_node::serial_msg :definition-)
      "float32 roll
float32 pitch
float32 yaw
float32 linear_x
float32 linear_y
float32 angular_z
")



(provide :serial_node/serial_msg "46c11c19de8f979808da3e975b371e2c")


