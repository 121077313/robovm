#include <nullvm.h>
#include <string.h>

static void throwUnsupportedOperationException(Env* env, char* msg) {
    Class* clazz = nvmFindClass(env, "java/lang/UnsupportedOperationException");
    if (!clazz) return;
    nvmThrowNew(env, clazz, msg);
}

static jint GetVersion(JNIEnv* env) {
    return JNI_VERSION_1_4;
}

static jclass DefineClass(JNIEnv* env, const char* name, jobject loader, const jbyte* buf, jsize len) {
    throwUnsupportedOperationException((Env*) *env, "DefineClass");
    return NULL;
}

static jclass FindClass(JNIEnv* env, const char* name) {
    return (jclass) nvmFindClass((Env*) *env, (char*) name);
}

static jmethodID FromReflectedMethod(JNIEnv* env, jobject method) {
    throwUnsupportedOperationException((Env*) *env, "FromReflectedMethod");
    return NULL;
}

static jfieldID FromReflectedField(JNIEnv* env, jobject field) {
    throwUnsupportedOperationException((Env*) *env, "FromReflectedField");
    return NULL;
}

static jobject ToReflectedMethod(JNIEnv* env, jclass cls, jmethodID methodID, jboolean isStatic) {
    throwUnsupportedOperationException((Env*) *env, "ToReflectedMethod");
    return NULL;
}

static jweak NewWeakGlobalRef(JNIEnv* env, jobject obj) {
    throwUnsupportedOperationException((Env*) *env, "NewWeakGlobalRef");
    return NULL;
}

static void DeleteWeakGlobalRef(JNIEnv* env, jweak obj) {
    throwUnsupportedOperationException((Env*) *env, "DeleteWeakGlobalRef");
}

static jint GetJavaVM(JNIEnv* env, JavaVM** vm) {
    throwUnsupportedOperationException((Env*) *env, "GetJavaVM");
    return -1;
}

static jint RegisterNatives(JNIEnv* env, jclass clazz, const JNINativeMethod* methods, jint nMethods) {
    throwUnsupportedOperationException((Env*) *env, "RegisterNatives");
    return -1;
}

static jint UnregisterNatives(JNIEnv* env, jclass clazz) {
    throwUnsupportedOperationException((Env*) *env, "UnregisterNatives");
    return -1;
}

static jclass GetSuperclass(JNIEnv* env, jclass sub) {
    return (jclass) ((Class*) sub)->superclass;
}

static jboolean IsAssignableFrom(JNIEnv* env, jclass sub, jclass sup) {
    return nvmIsAssignableFrom((Env*) *env, (Class*) sub, (Class*) sup);
}

static jobject ToReflectedField(JNIEnv* env, jclass cls, jfieldID fieldID, jboolean isStatic) {
    throwUnsupportedOperationException((Env*) *env, "ToReflectedField");
    return NULL;
}

static jint Throw(JNIEnv* env, jthrowable obj) {
    return nvmThrow((Env*) *env, (Object*) obj);
}

static jint ThrowNew(JNIEnv* env, jclass clazz, const char* msg) {
    return nvmThrowNew((Env*) *env, (Class*) clazz, (char*) msg);
}

static jthrowable ExceptionOccurred(JNIEnv* env) {
    return (jthrowable) nvmExceptionOccurred((Env*) *env);
}

static void ExceptionDescribe(JNIEnv* env) {
    // TODO: Implement me properly
    Object* e = nvmExceptionOccurred((Env*) *env);
    fprintf(stderr, "ExceptionDescribe: %s\n", e->clazz->name);
}

static void ExceptionClear(JNIEnv* env) {
    (jthrowable) nvmExceptionClear((Env*) *env);
}

static void FatalError(JNIEnv* env, const char* msg) {
    nvmAbort((char*) msg);
}

static jint PushLocalFrame(JNIEnv* env, jint cap) {
    return 0;
}

static jobject PopLocalFrame(JNIEnv* env, jobject res) {
    return res;
}

static jobject NewGlobalRef(JNIEnv* env, jobject lobj) {
    return lobj;
}

static void DeleteGlobalRef(JNIEnv* env, jobject gref) {
}

static void DeleteLocalRef(JNIEnv* env, jobject obj) {
}

static jboolean IsSameObject(JNIEnv* env, jobject obj1, jobject obj2) {
    return obj1 == obj2;
}

static jobject NewLocalRef(JNIEnv* env, jobject ref) {
    return ref;
}

static jint EnsureLocalCapacity(JNIEnv* env, jint capacity) {
    return 0;
}

static jobject AllocObject(JNIEnv* env, jclass clazz) {
    return (jobject) nvmAllocateObject((Env*) *env, (Class*) clazz);
}

static jobject NewObjectV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return (jobject) nvmNewObjectV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jobject NewObjectA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return (jobject) nvmNewObjectA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jobject NewObject(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return NewObjectV(env, clazz, methodID, args);
}

static jclass GetObjectClass(JNIEnv* env, jobject obj) {
    return (jclass) ((Object*) obj)->clazz;
}

static jboolean IsInstanceOf(JNIEnv* env, jobject obj, jclass clazz) {
    return nvmIsInstanceOf((Env*) *env, (Object*) obj, (Class*) clazz);
}

static jmethodID GetMethodID(JNIEnv* env, jclass clazz, const char* name, const char* sig) {
    return (jmethodID) nvmGetInstanceMethod((Env*) *env, (Class*) clazz, (char*) name, (char*) sig);
}

static jobject CallObjectMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return (jobject) nvmCallObjectInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jobject CallObjectMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return (jobject) nvmCallObjectInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jobject CallObjectMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallObjectMethodV(env, obj, methodID, args);
}

static jboolean CallBooleanMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallBooleanInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jboolean CallBooleanMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue*  args) {
    return nvmCallBooleanInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jboolean CallBooleanMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallBooleanMethodV(env, obj, methodID, args);
}

static jbyte CallByteMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallByteInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jbyte CallByteMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallByteInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jbyte CallByteMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallByteMethodV(env, obj, methodID, args);
}

static jchar CallCharMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallCharInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jchar CallCharMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallCharInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jchar CallCharMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallCharMethodV(env, obj, methodID, args);
}

static jshort CallShortMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallShortInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jshort CallShortMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallShortInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jshort CallShortMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallShortMethodV(env, obj, methodID, args);
}

static jint CallIntMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallIntInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jint CallIntMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallIntInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jint CallIntMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallIntMethodV(env, obj, methodID, args);
}

static jlong CallLongMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallLongInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jlong CallLongMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallLongInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jlong CallLongMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallLongMethodV(env, obj, methodID, args);
}

static jfloat CallFloatMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallFloatInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jfloat CallFloatMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallFloatInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jfloat CallFloatMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallFloatMethodV(env, obj, methodID, args);
}

static jdouble CallDoubleMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    return nvmCallDoubleInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jdouble CallDoubleMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue* args) {
    return nvmCallDoubleInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jdouble CallDoubleMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallDoubleMethodV(env, obj, methodID, args);
}

static void CallVoidMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    nvmCallVoidInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static void CallVoidMethodA(JNIEnv* env, jobject obj, jmethodID methodID, jvalue*  args) {
    nvmCallVoidInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static void CallVoidMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    CallVoidMethodV(env, obj, methodID, args);
}

static jobject CallNonvirtualObjectMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return (jobject) nvmCallNonvirtualObjectInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jobject CallNonvirtualObjectMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue*  args) {
    return (jobject) nvmCallNonvirtualObjectInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jobject CallNonvirtualObjectMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualObjectMethodV(env, obj, clazz, methodID, args);
}

static jboolean CallNonvirtualBooleanMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualBooleanInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jboolean CallNonvirtualBooleanMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue*  args) {
    return nvmCallNonvirtualBooleanInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jboolean CallNonvirtualBooleanMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualBooleanMethodV(env, obj, clazz, methodID, args);
}

static jbyte CallNonvirtualByteMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualByteInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jbyte CallNonvirtualByteMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualByteInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jbyte CallNonvirtualByteMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualByteMethodV(env, obj, clazz, methodID, args);
}

static jchar CallNonvirtualCharMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualCharInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jchar CallNonvirtualCharMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualCharInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jchar CallNonvirtualCharMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualCharMethodV(env, obj, clazz, methodID, args);
}

static jshort CallNonvirtualShortMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualShortInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jshort CallNonvirtualShortMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualShortInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jshort CallNonvirtualShortMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualShortMethodV(env, obj, clazz, methodID, args);
}

static jint CallNonvirtualIntMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualIntInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jint CallNonvirtualIntMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualIntInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jint CallNonvirtualIntMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualIntMethodV(env, obj, clazz, methodID, args);
}

static jlong CallNonvirtualLongMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualLongInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jlong CallNonvirtualLongMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualLongInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jlong CallNonvirtualLongMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualLongMethodV(env, obj, clazz, methodID, args);
}

static jfloat CallNonvirtualFloatMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualFloatInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jfloat CallNonvirtualFloatMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualFloatInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jfloat CallNonvirtualFloatMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualFloatMethodV(env, obj, clazz, methodID, args);
}

static jdouble CallNonvirtualDoubleMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallNonvirtualDoubleInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jdouble CallNonvirtualDoubleMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallNonvirtualDoubleInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static jdouble CallNonvirtualDoubleMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallNonvirtualDoubleMethodV(env, obj, clazz, methodID, args);
}

static void CallNonvirtualVoidMethodV(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    nvmCallNonvirtualVoidInstanceMethodV((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static void CallNonvirtualVoidMethodA(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, jvalue*  args) {
    nvmCallNonvirtualVoidInstanceMethodA((Env*) *env, (Object*) obj, (Method*) methodID, args);
}

static void CallNonvirtualVoidMethod(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    CallNonvirtualVoidMethodV(env, obj, clazz, methodID, args);
}

static jfieldID GetFieldID(JNIEnv* env, jclass clazz, const char* name, const char* sig) {
    return (jfieldID) nvmGetInstanceField((Env*) *env, (Class*) clazz, (char*) name, (char*) sig);
}

static jobject GetObjectField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return (jobject) nvmGetObjectInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jboolean GetBooleanField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetBooleanInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jbyte GetByteField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetByteInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jchar GetCharField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetCharInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jshort GetShortField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetShortInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jint GetIntField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetIntInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jlong GetLongField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetLongInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jfloat GetFloatField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetFloatInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static jdouble GetDoubleField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    return nvmGetDoubleInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID);
}

static void SetObjectField(JNIEnv* env, jobject obj, jfieldID fieldID, jobject val) {
    nvmSetObjectInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, (Object*) val);
}

static void SetBooleanField(JNIEnv* env, jobject obj, jfieldID fieldID, jboolean val) {
    nvmSetBooleanInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetByteField(JNIEnv* env, jobject obj, jfieldID fieldID, jbyte val) {
    nvmSetByteInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetCharField(JNIEnv* env, jobject obj, jfieldID fieldID, jchar val) {
    nvmSetCharInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetShortField(JNIEnv* env, jobject obj, jfieldID fieldID, jshort val) {
    nvmSetShortInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetIntField(JNIEnv* env, jobject obj, jfieldID fieldID, jint val) {
    nvmSetIntInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetLongField(JNIEnv* env, jobject obj, jfieldID fieldID, jlong val) {
    nvmSetLongInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetFloatField(JNIEnv* env, jobject obj, jfieldID fieldID, jfloat val) {
    nvmSetFloatInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static void SetDoubleField(JNIEnv* env, jobject obj, jfieldID fieldID, jdouble val) {
    nvmSetDoubleInstanceFieldValue((Env*) *env, (Object*) obj, (InstanceField*) fieldID, val);
}

static jmethodID GetStaticMethodID(JNIEnv* env, jclass clazz, const char* name, const char* sig) {
    return (jmethodID) nvmGetClassMethod((Env*) *env, (Class*) clazz, (char*) name, (char*) sig);
}

static jobject CallStaticObjectMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return (jobject) nvmCallObjectClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jobject CallStaticObjectMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return (jobject) nvmCallObjectClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jobject CallStaticObjectMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticObjectMethodV(env, clazz, methodID, args);
}

static jboolean CallStaticBooleanMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallBooleanClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jboolean CallStaticBooleanMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallBooleanClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jboolean CallStaticBooleanMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticBooleanMethodV(env, clazz, methodID, args);
}

static jbyte CallStaticByteMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallByteClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jbyte CallStaticByteMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallByteClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jbyte CallStaticByteMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticByteMethodV(env, clazz, methodID, args);
}

static jchar CallStaticCharMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallCharClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jchar CallStaticCharMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallCharClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jchar CallStaticCharMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticCharMethodV(env, clazz, methodID, args);
}

static jshort CallStaticShortMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallShortClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jshort CallStaticShortMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallShortClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jshort CallStaticShortMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticShortMethodV(env, clazz, methodID, args);
}

static jint CallStaticIntMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallIntClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jint CallStaticIntMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallIntClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jint CallStaticIntMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticIntMethodV(env, clazz, methodID, args);
}

static jlong CallStaticLongMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallLongClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jlong CallStaticLongMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallLongClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jlong CallStaticLongMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticLongMethodV(env, clazz, methodID, args);
}

static jfloat CallStaticFloatMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallFloatClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jfloat CallStaticFloatMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallFloatClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jfloat CallStaticFloatMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticFloatMethodV(env, clazz, methodID, args);
}

static jdouble CallStaticDoubleMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    return nvmCallDoubleClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jdouble CallStaticDoubleMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue* args) {
    return nvmCallDoubleClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static jdouble CallStaticDoubleMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    return CallStaticDoubleMethodV(env, clazz, methodID, args);
}

static void CallStaticVoidMethodV(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args) {
    nvmCallVoidClassMethodV((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static void CallStaticVoidMethodA(JNIEnv* env, jclass clazz, jmethodID methodID, jvalue*  args) {
    nvmCallVoidClassMethodA((Env*) *env, (Class*) clazz, (Method*) methodID, args);
}

static void CallStaticVoidMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    CallStaticVoidMethodV(env, clazz, methodID, args);
}

static jfieldID GetStaticFieldID(JNIEnv* env, jclass clazz, const char* name, const char* sig) {
    return (jfieldID) nvmGetClassField((Env*) *env, (Class*) clazz, (char*) name, (char*) sig);
}

static jobject GetStaticObjectField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return (jobject) nvmGetObjectClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jboolean GetStaticBooleanField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetBooleanClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jbyte GetStaticByteField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetByteClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jchar GetStaticCharField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetCharClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jshort GetStaticShortField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetShortClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jint GetStaticIntField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetIntClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jlong GetStaticLongField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetLongClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jfloat GetStaticFloatField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetFloatClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static jdouble GetStaticDoubleField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
    return nvmGetDoubleClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID);
}

static void SetStaticObjectField(JNIEnv* env, jclass clazz, jfieldID fieldID, jobject val) {
    nvmSetObjectClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, (Object*) val);
}

static void SetStaticBooleanField(JNIEnv* env, jclass clazz, jfieldID fieldID, jboolean val) {
    nvmSetBooleanClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticByteField(JNIEnv* env, jclass clazz, jfieldID fieldID, jbyte val) {
    nvmSetByteClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticCharField(JNIEnv* env, jclass clazz, jfieldID fieldID, jchar val) {
    nvmSetCharClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticShortField(JNIEnv* env, jclass clazz, jfieldID fieldID, jshort val) {
    nvmSetShortClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticIntField(JNIEnv* env, jclass clazz, jfieldID fieldID, jint val) {
    nvmSetIntClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticLongField(JNIEnv* env, jclass clazz, jfieldID fieldID, jlong val) {
    nvmSetLongClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticFloatField(JNIEnv* env, jclass clazz, jfieldID fieldID, jfloat val) {
    nvmSetFloatClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static void SetStaticDoubleField(JNIEnv* env, jclass clazz, jfieldID fieldID, jdouble val) {
    nvmSetDoubleClassFieldValue((Env*) *env, (Class*) clazz, (ClassField*) fieldID, val);
}

static jstring NewString(JNIEnv* env, const jchar* unicode, jsize len) {
    return (jstring) nvmNewString((Env*) *env, (jchar*) unicode, len);
}

static jsize GetStringLength(JNIEnv* env, jstring str) {
    return nvmGetStringLength((Env*) *env, (Object*) str);
}

static const jchar* GetStringChars(JNIEnv* env, jstring str, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_TRUE;
    return nvmGetStringChars((Env*) *env, (Object*) str);
}

static void ReleaseStringChars(JNIEnv* env, jstring str, const jchar* chars) {
}
  
static jstring NewStringUTF(JNIEnv* env, const char* utf) {
    return (jstring) nvmNewStringUTF((Env*) *env, (char*) utf, -1);
}

static jsize GetStringUTFLength(JNIEnv* env, jstring str) {
    return nvmGetStringUTFLength((Env*) *env, (Object*) str);
}

static const char* GetStringUTFChars(JNIEnv* env, jstring str, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_TRUE;
    return nvmGetStringUTFChars((Env*) *env, (Object*) str);
}

static void ReleaseStringUTFChars(JNIEnv* env, jstring str, const char* chars) {
} 

static jsize GetArrayLength(JNIEnv* env, jarray array) {
    return ((Array*) array)->length;
}

static jobjectArray NewObjectArray(JNIEnv* env, jsize len, jclass clazz, jobject init) {
    ObjectArray* array = nvmNewObjectArray((Env*) *env, len, (Class*) clazz, NULL);
    if (!array) return NULL;
    if (init) {
        jint i;
        for (i = 0; i < len; i++) {
            array->values[i] = (Object*) init;
        }
    }
    return (jobjectArray) array;
}

static jobject GetObjectArrayElement(JNIEnv* env, jobjectArray array, jsize index) {
    return (jobject) ((ObjectArray*) array)->values[index];
}

static void SetObjectArrayElement(JNIEnv* env, jobjectArray array, jsize index, jobject val) {
    ((ObjectArray*) array)->values[index] = (Object*) val;
}

static jbooleanArray NewBooleanArray(JNIEnv* env, jsize len) {
    return (jbooleanArray) nvmNewBooleanArray((Env*) *env, len);
}

static jbyteArray NewByteArray(JNIEnv* env, jsize len) {
    return (jbyteArray) nvmNewByteArray((Env*) *env, len);
}

static jcharArray NewCharArray(JNIEnv* env, jsize len) {
    return (jcharArray) nvmNewCharArray((Env*) *env, len);
}

static jshortArray NewShortArray(JNIEnv* env, jsize len) {
    return (jshortArray) nvmNewShortArray((Env*) *env, len);
}

static jintArray NewIntArray(JNIEnv* env, jsize len) {
    return (jintArray) nvmNewIntArray((Env*) *env, len);
}

static jlongArray NewLongArray(JNIEnv* env, jsize len) {
    return (jlongArray) nvmNewLongArray((Env*) *env, len);
}

static jfloatArray NewFloatArray(JNIEnv* env, jsize len) {
    return (jfloatArray) nvmNewFloatArray((Env*) *env, len);
}

static jdoubleArray NewDoubleArray(JNIEnv* env, jsize len) {
    return (jdoubleArray) nvmNewDoubleArray((Env*) *env, len);
}

static jboolean* GetBooleanArrayElements(JNIEnv* env, jbooleanArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((BooleanArray*) array)->values;
}

static jbyte* GetByteArrayElements(JNIEnv* env, jbyteArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((ByteArray*) array)->values;
}

static jchar* GetCharArrayElements(JNIEnv* env, jcharArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((CharArray*) array)->values;
}

static jshort* GetShortArrayElements(JNIEnv* env, jshortArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((ShortArray*) array)->values;
}

static jint* GetIntArrayElements(JNIEnv* env, jintArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((IntArray*) array)->values;
}

static jlong* GetLongArrayElements(JNIEnv* env, jlongArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((LongArray*) array)->values;
}

static jfloat* GetFloatArrayElements(JNIEnv* env, jfloatArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((FloatArray*) array)->values;
}

static jdouble* GetDoubleArrayElements(JNIEnv* env, jdoubleArray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((DoubleArray*) array)->values;
}


static void ReleaseBooleanArrayElements(JNIEnv* env, jbooleanArray array, jboolean* elems, jint mode) {
}

static void ReleaseByteArrayElements(JNIEnv* env, jbyteArray array, jbyte* elems, jint mode) {
}

static void ReleaseCharArrayElements(JNIEnv* env, jcharArray array, jchar* elems, jint mode) {
}

static void ReleaseShortArrayElements(JNIEnv* env, jshortArray array, jshort* elems, jint mode) {
}

static void ReleaseIntArrayElements(JNIEnv* env, jintArray array, jint* elems, jint mode) {
}

static void ReleaseLongArrayElements(JNIEnv* env, jlongArray array, jlong* elems, jint mode) {
}

static void ReleaseFloatArrayElements(JNIEnv* env, jfloatArray array, jfloat* elems, jint mode) {
}

static void ReleaseDoubleArrayElements(JNIEnv* env, jdoubleArray array, jdouble* elems, jint mode) {
}

static jboolean checkBounds(Env* env, Array* array, jint start, jint len) {
    jsize length = array->length;
    jsize end = start + len;
    if (start < 0 || len < 0 || end > length) {
        // TODO: Nicer message?
        nvmThrowArrayIndexOutOfBoundsException(env, start);
        return FALSE;
    }
    return TRUE;
}

static void GetBooleanArrayRegion(JNIEnv* env, jbooleanArray array, jsize start, jsize len, jboolean* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((BooleanArray*) array)->values + start, sizeof(jboolean) * len);
}

static void GetByteArrayRegion(JNIEnv* env, jbyteArray array, jsize start, jsize len, jbyte* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((ByteArray*) array)->values + start, sizeof(jbyte) * len);
}

static void GetCharArrayRegion(JNIEnv* env, jcharArray array, jsize start, jsize len, jchar* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((CharArray*) array)->values + start, sizeof(jchar) * len);
}

static void GetShortArrayRegion(JNIEnv* env, jshortArray array, jsize start, jsize len, jshort* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((ShortArray*) array)->values + start, sizeof(jshort) * len);
}

static void GetIntArrayRegion(JNIEnv* env, jintArray array, jsize start, jsize len, jint* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((IntArray*) array)->values + start, sizeof(jint) * len);
}

static void GetLongArrayRegion(JNIEnv* env, jlongArray array, jsize start, jsize len, jlong* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((LongArray*) array)->values + start, sizeof(jlong) * len);
}

static void GetFloatArrayRegion(JNIEnv* env, jfloatArray array, jsize start, jsize len, jfloat* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((FloatArray*) array)->values + start, sizeof(jfloat) * len);
}

static void GetDoubleArrayRegion(JNIEnv* env, jdoubleArray array, jsize start, jsize len, jdouble* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(buf, ((DoubleArray*) array)->values + start, sizeof(jdouble) * len);
}

static void SetBooleanArrayRegion(JNIEnv* env, jbooleanArray array, jsize start, jsize len, jboolean* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((BooleanArray*) array)->values + start, buf, sizeof(jboolean) * len);
}

static void SetByteArrayRegion(JNIEnv* env, jbyteArray array, jsize start, jsize len, jbyte* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((ByteArray*) array)->values + start, buf, sizeof(jbyte) * len);
}

static void SetCharArrayRegion(JNIEnv* env, jcharArray array, jsize start, jsize len, jchar* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((CharArray*) array)->values + start, buf, sizeof(jchar) * len);
}

static void SetShortArrayRegion(JNIEnv* env, jshortArray array, jsize start, jsize len, jshort* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((ShortArray*) array)->values + start, buf, sizeof(jshort) * len);
}

static void SetIntArrayRegion(JNIEnv* env, jintArray array, jsize start, jsize len, jint* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((IntArray*) array)->values + start, buf, sizeof(jint) * len);
}

static void SetLongArrayRegion(JNIEnv* env, jlongArray array, jsize start, jsize len, jlong* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((LongArray*) array)->values + start, buf, sizeof(jlong) * len);
}

static void SetFloatArrayRegion(JNIEnv* env, jfloatArray array, jsize start, jsize len, jfloat* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((FloatArray*) array)->values + start, buf, sizeof(jfloat) * len);
}

static void SetDoubleArrayRegion(JNIEnv* env, jdoubleArray array, jsize start, jsize len, jdouble* buf) {
    if (!checkBounds((Env*) *env, (Array*) array, start, len)) return;
    memcpy(((DoubleArray*) array)->values + start, buf, sizeof(jdouble) * len);
}

static jint MonitorEnter(JNIEnv* env, jobject obj) {
    return nvmMonitorEnter((Env*) *env, (Object*) obj);
}

static jint MonitorExit(JNIEnv* env, jobject obj) {
    return nvmMonitorExit((Env*) *env, (Object*) obj);
}
 
static void GetStringRegion(JNIEnv* env, jstring str, jsize start, jsize len, jchar* buf) {
    nvmGetStringRegion((Env*) *env, (Object*) str, start, len, buf);
}

static void GetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize len, char* buf) {
    nvmGetStringUTFRegion((Env*) *env, (Object*) str, start, len, buf);
}

static void* GetPrimitiveArrayCritical(JNIEnv* env, jarray array, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    return ((Array*) array)->values;
}

static void ReleasePrimitiveArrayCritical(JNIEnv* env, jarray array, void* carray, jint mode) {
}

static const jchar* GetStringCritical(JNIEnv* env, jstring str, jboolean* isCopy) {
    return GetStringChars(env, str, isCopy);
}

static void ReleaseStringCritical(JNIEnv* env, jstring str, const jchar* chars) {
    ReleaseStringChars(env, str, chars);
}

static jboolean ExceptionCheck(JNIEnv* env) {
    return nvmExceptionCheck((Env*) *env);
}

static jobject NewDirectByteBuffer(JNIEnv* env, void* address, jlong capacity) {
    // TODO: Implement me
    return NULL;
}

static void* GetDirectBufferAddress(JNIEnv* env, jobject buf) {
    // TODO: Implement me
    return NULL;
}

static jlong GetDirectBufferCapacity(JNIEnv* env, jobject buf) {
    // TODO: Implement me
    return -1;
}

Env* nvmCreateEnv(void) {
    Env* env = (Env*) GC_MALLOC(sizeof(Env));
    if (!env) return NULL;

    env->jni.GetVersion = GetVersion;
    env->jni.DefineClass = DefineClass;
    env->jni.FindClass = FindClass;
    env->jni.FromReflectedMethod = FromReflectedMethod;
    env->jni.FromReflectedField = FromReflectedField;
    env->jni.ToReflectedMethod = ToReflectedMethod;
    env->jni.GetSuperclass = GetSuperclass;
    env->jni.IsAssignableFrom = IsAssignableFrom;
    env->jni.ToReflectedField = ToReflectedField;
    env->jni.Throw = Throw;
    env->jni.ThrowNew = ThrowNew;
    env->jni.ExceptionOccurred = ExceptionOccurred;
    env->jni.ExceptionDescribe = ExceptionDescribe;
    env->jni.ExceptionClear = ExceptionClear;
    env->jni.FatalError = FatalError;
    env->jni.PushLocalFrame = PushLocalFrame;
    env->jni.PopLocalFrame = PopLocalFrame;
    env->jni.NewGlobalRef = NewGlobalRef;
    env->jni.DeleteGlobalRef = DeleteGlobalRef;
    env->jni.DeleteLocalRef = DeleteLocalRef;
    env->jni.IsSameObject = IsSameObject;
    env->jni.NewLocalRef = NewLocalRef;
    env->jni.EnsureLocalCapacity = EnsureLocalCapacity;
    env->jni.AllocObject = AllocObject;
    env->jni.NewObject = NewObject;
    env->jni.NewObjectV = NewObjectV;
    env->jni.NewObjectA = NewObjectA;
    env->jni.GetObjectClass = GetObjectClass;
    env->jni.IsInstanceOf = IsInstanceOf;
    env->jni.GetMethodID = GetMethodID;
    env->jni.CallObjectMethod = CallObjectMethod;
    env->jni.CallObjectMethodV = CallObjectMethodV;
    env->jni.CallObjectMethodA = CallObjectMethodA;
    env->jni.CallBooleanMethod = CallBooleanMethod;
    env->jni.CallBooleanMethodV = CallBooleanMethodV;
    env->jni.CallBooleanMethodA = CallBooleanMethodA;
    env->jni.CallByteMethod = CallByteMethod;
    env->jni.CallByteMethodV = CallByteMethodV;
    env->jni.CallByteMethodA = CallByteMethodA;
    env->jni.CallCharMethod = CallCharMethod;
    env->jni.CallCharMethodV = CallCharMethodV;
    env->jni.CallCharMethodA = CallCharMethodA;
    env->jni.CallShortMethod = CallShortMethod;
    env->jni.CallShortMethodV = CallShortMethodV;
    env->jni.CallShortMethodA = CallShortMethodA;
    env->jni.CallIntMethod = CallIntMethod;
    env->jni.CallIntMethodV = CallIntMethodV;
    env->jni.CallIntMethodA = CallIntMethodA;
    env->jni.CallLongMethod = CallLongMethod;
    env->jni.CallLongMethodV = CallLongMethodV;
    env->jni.CallLongMethodA = CallLongMethodA;
    env->jni.CallFloatMethod = CallFloatMethod;
    env->jni.CallFloatMethodV = CallFloatMethodV;
    env->jni.CallFloatMethodA = CallFloatMethodA;
    env->jni.CallDoubleMethod = CallDoubleMethod;
    env->jni.CallDoubleMethodV = CallDoubleMethodV;
    env->jni.CallDoubleMethodA = CallDoubleMethodA;
    env->jni.CallVoidMethod = CallVoidMethod;
    env->jni.CallVoidMethodV = CallVoidMethodV;
    env->jni.CallVoidMethodA = CallVoidMethodA;
    env->jni.CallNonvirtualObjectMethod = CallNonvirtualObjectMethod;
    env->jni.CallNonvirtualObjectMethodV = CallNonvirtualObjectMethodV;
    env->jni.CallNonvirtualObjectMethodA = CallNonvirtualObjectMethodA;
    env->jni.CallNonvirtualBooleanMethod = CallNonvirtualBooleanMethod;
    env->jni.CallNonvirtualBooleanMethodV = CallNonvirtualBooleanMethodV;
    env->jni.CallNonvirtualBooleanMethodA = CallNonvirtualBooleanMethodA;
    env->jni.CallNonvirtualByteMethod = CallNonvirtualByteMethod;
    env->jni.CallNonvirtualByteMethodV = CallNonvirtualByteMethodV;
    env->jni.CallNonvirtualByteMethodA = CallNonvirtualByteMethodA;
    env->jni.CallNonvirtualCharMethod = CallNonvirtualCharMethod;
    env->jni.CallNonvirtualCharMethodV = CallNonvirtualCharMethodV;
    env->jni.CallNonvirtualCharMethodA = CallNonvirtualCharMethodA;
    env->jni.CallNonvirtualShortMethod = CallNonvirtualShortMethod;
    env->jni.CallNonvirtualShortMethodV = CallNonvirtualShortMethodV;
    env->jni.CallNonvirtualShortMethodA = CallNonvirtualShortMethodA;
    env->jni.CallNonvirtualIntMethod = CallNonvirtualIntMethod;
    env->jni.CallNonvirtualIntMethodV = CallNonvirtualIntMethodV;
    env->jni.CallNonvirtualIntMethodA = CallNonvirtualIntMethodA;
    env->jni.CallNonvirtualLongMethod = CallNonvirtualLongMethod;
    env->jni.CallNonvirtualLongMethodV = CallNonvirtualLongMethodV;
    env->jni.CallNonvirtualLongMethodA = CallNonvirtualLongMethodA;
    env->jni.CallNonvirtualFloatMethod = CallNonvirtualFloatMethod;
    env->jni.CallNonvirtualFloatMethodV = CallNonvirtualFloatMethodV;
    env->jni.CallNonvirtualFloatMethodA = CallNonvirtualFloatMethodA;
    env->jni.CallNonvirtualDoubleMethod = CallNonvirtualDoubleMethod;
    env->jni.CallNonvirtualDoubleMethodV = CallNonvirtualDoubleMethodV;
    env->jni.CallNonvirtualDoubleMethodA = CallNonvirtualDoubleMethodA;
    env->jni.CallNonvirtualVoidMethod = CallNonvirtualVoidMethod;
    env->jni.CallNonvirtualVoidMethodV = CallNonvirtualVoidMethodV;
    env->jni.CallNonvirtualVoidMethodA = CallNonvirtualVoidMethodA;
    env->jni.GetFieldID = GetFieldID;
    env->jni.GetObjectField = GetObjectField;
    env->jni.GetBooleanField = GetBooleanField;
    env->jni.GetByteField = GetByteField;
    env->jni.GetCharField = GetCharField;
    env->jni.GetShortField = GetShortField;
    env->jni.GetIntField = GetIntField;
    env->jni.GetLongField = GetLongField;
    env->jni.GetFloatField = GetFloatField;
    env->jni.GetDoubleField = GetDoubleField;
    env->jni.SetObjectField = SetObjectField;
    env->jni.SetBooleanField = SetBooleanField;
    env->jni.SetByteField = SetByteField;
    env->jni.SetCharField = SetCharField;
    env->jni.SetShortField = SetShortField;
    env->jni.SetIntField = SetIntField;
    env->jni.SetLongField = SetLongField;
    env->jni.SetFloatField = SetFloatField;
    env->jni.SetDoubleField = SetDoubleField;
    env->jni.GetStaticMethodID = GetStaticMethodID;
    env->jni.CallStaticObjectMethod = CallStaticObjectMethod;
    env->jni.CallStaticObjectMethodV = CallStaticObjectMethodV;
    env->jni.CallStaticObjectMethodA = CallStaticObjectMethodA;
    env->jni.CallStaticBooleanMethod = CallStaticBooleanMethod;
    env->jni.CallStaticBooleanMethodV = CallStaticBooleanMethodV;
    env->jni.CallStaticBooleanMethodA = CallStaticBooleanMethodA;
    env->jni.CallStaticByteMethod = CallStaticByteMethod;
    env->jni.CallStaticByteMethodV = CallStaticByteMethodV;
    env->jni.CallStaticByteMethodA = CallStaticByteMethodA;
    env->jni.CallStaticCharMethod = CallStaticCharMethod;
    env->jni.CallStaticCharMethodV = CallStaticCharMethodV;
    env->jni.CallStaticCharMethodA = CallStaticCharMethodA;
    env->jni.CallStaticShortMethod = CallStaticShortMethod;
    env->jni.CallStaticShortMethodV = CallStaticShortMethodV;
    env->jni.CallStaticShortMethodA = CallStaticShortMethodA;
    env->jni.CallStaticIntMethod = CallStaticIntMethod;
    env->jni.CallStaticIntMethodV = CallStaticIntMethodV;
    env->jni.CallStaticIntMethodA = CallStaticIntMethodA;
    env->jni.CallStaticLongMethod = CallStaticLongMethod;
    env->jni.CallStaticLongMethodV = CallStaticLongMethodV;
    env->jni.CallStaticLongMethodA = CallStaticLongMethodA;
    env->jni.CallStaticFloatMethod = CallStaticFloatMethod;
    env->jni.CallStaticFloatMethodV = CallStaticFloatMethodV;
    env->jni.CallStaticFloatMethodA = CallStaticFloatMethodA;
    env->jni.CallStaticDoubleMethod = CallStaticDoubleMethod;
    env->jni.CallStaticDoubleMethodV = CallStaticDoubleMethodV;
    env->jni.CallStaticDoubleMethodA = CallStaticDoubleMethodA;
    env->jni.CallStaticVoidMethod = CallStaticVoidMethod;
    env->jni.CallStaticVoidMethodV = CallStaticVoidMethodV;
    env->jni.CallStaticVoidMethodA = CallStaticVoidMethodA;
    env->jni.GetStaticFieldID = GetStaticFieldID;
    env->jni.GetStaticObjectField = GetStaticObjectField;
    env->jni.GetStaticBooleanField = GetStaticBooleanField;
    env->jni.GetStaticByteField = GetStaticByteField;
    env->jni.GetStaticCharField = GetStaticCharField;
    env->jni.GetStaticShortField = GetStaticShortField;
    env->jni.GetStaticIntField = GetStaticIntField;
    env->jni.GetStaticLongField = GetStaticLongField;
    env->jni.GetStaticFloatField = GetStaticFloatField;
    env->jni.GetStaticDoubleField = GetStaticDoubleField;
    env->jni.SetStaticObjectField = SetStaticObjectField;
    env->jni.SetStaticBooleanField = SetStaticBooleanField;
    env->jni.SetStaticByteField = SetStaticByteField;
    env->jni.SetStaticCharField = SetStaticCharField;
    env->jni.SetStaticShortField = SetStaticShortField;
    env->jni.SetStaticIntField = SetStaticIntField;
    env->jni.SetStaticLongField = SetStaticLongField;
    env->jni.SetStaticFloatField = SetStaticFloatField;
    env->jni.SetStaticDoubleField = SetStaticDoubleField;
    env->jni.NewString = NewString;
    env->jni.GetStringLength = GetStringLength;
    env->jni.GetStringChars = GetStringChars;
    env->jni.ReleaseStringChars = ReleaseStringChars;
    env->jni.NewStringUTF = NewStringUTF;
    env->jni.GetStringUTFLength = GetStringUTFLength;
    env->jni.GetStringUTFChars = GetStringUTFChars;
    env->jni.ReleaseStringUTFChars = ReleaseStringUTFChars;
    env->jni.GetArrayLength = GetArrayLength;
    env->jni.NewObjectArray = NewObjectArray;
    env->jni.GetObjectArrayElement = GetObjectArrayElement;
    env->jni.SetObjectArrayElement = SetObjectArrayElement;
    env->jni.NewBooleanArray = NewBooleanArray;
    env->jni.NewByteArray = NewByteArray;
    env->jni.NewCharArray = NewCharArray;
    env->jni.NewShortArray = NewShortArray;
    env->jni.NewIntArray = NewIntArray;
    env->jni.NewLongArray = NewLongArray;
    env->jni.NewFloatArray = NewFloatArray;
    env->jni.NewDoubleArray = NewDoubleArray;
    env->jni.GetBooleanArrayElements = GetBooleanArrayElements;
    env->jni.GetByteArrayElements = GetByteArrayElements;
    env->jni.GetCharArrayElements = GetCharArrayElements;
    env->jni.GetShortArrayElements = GetShortArrayElements;
    env->jni.GetIntArrayElements = GetIntArrayElements;
    env->jni.GetLongArrayElements = GetLongArrayElements;
    env->jni.GetFloatArrayElements = GetFloatArrayElements;
    env->jni.GetDoubleArrayElements = GetDoubleArrayElements;
    env->jni.ReleaseBooleanArrayElements = ReleaseBooleanArrayElements;
    env->jni.ReleaseByteArrayElements = ReleaseByteArrayElements;
    env->jni.ReleaseCharArrayElements = ReleaseCharArrayElements;
    env->jni.ReleaseShortArrayElements = ReleaseShortArrayElements;
    env->jni.ReleaseIntArrayElements = ReleaseIntArrayElements;
    env->jni.ReleaseLongArrayElements = ReleaseLongArrayElements;
    env->jni.ReleaseFloatArrayElements = ReleaseFloatArrayElements;
    env->jni.ReleaseDoubleArrayElements = ReleaseDoubleArrayElements;
    env->jni.GetBooleanArrayRegion = GetBooleanArrayRegion;
    env->jni.GetByteArrayRegion = GetByteArrayRegion;
    env->jni.GetCharArrayRegion = GetCharArrayRegion;
    env->jni.GetShortArrayRegion = GetShortArrayRegion;
    env->jni.GetIntArrayRegion = GetIntArrayRegion;
    env->jni.GetLongArrayRegion = GetLongArrayRegion;
    env->jni.GetFloatArrayRegion = GetFloatArrayRegion;
    env->jni.GetDoubleArrayRegion = GetDoubleArrayRegion;
    env->jni.SetBooleanArrayRegion = SetBooleanArrayRegion;
    env->jni.SetByteArrayRegion = SetByteArrayRegion;
    env->jni.SetCharArrayRegion = SetCharArrayRegion;
    env->jni.SetShortArrayRegion = SetShortArrayRegion;
    env->jni.SetIntArrayRegion = SetIntArrayRegion;
    env->jni.SetLongArrayRegion = SetLongArrayRegion;
    env->jni.SetFloatArrayRegion = SetFloatArrayRegion;
    env->jni.SetDoubleArrayRegion = SetDoubleArrayRegion;
    env->jni.RegisterNatives = RegisterNatives;
    env->jni.UnregisterNatives = UnregisterNatives;
    env->jni.MonitorEnter = MonitorEnter;
    env->jni.MonitorExit = MonitorExit;
    env->jni.GetJavaVM = GetJavaVM;
    env->jni.GetStringRegion = GetStringRegion;
    env->jni.GetStringUTFRegion = GetStringUTFRegion;
    env->jni.GetPrimitiveArrayCritical = GetPrimitiveArrayCritical;
    env->jni.ReleasePrimitiveArrayCritical = ReleasePrimitiveArrayCritical;
    env->jni.GetStringCritical = GetStringCritical;
    env->jni.ReleaseStringCritical = ReleaseStringCritical;
    env->jni.NewWeakGlobalRef = NewWeakGlobalRef;
    env->jni.DeleteWeakGlobalRef = DeleteWeakGlobalRef;
    env->jni.ExceptionCheck = ExceptionCheck;
    env->jni.NewDirectByteBuffer = NewDirectByteBuffer;
    env->jni.GetDirectBufferAddress = GetDirectBufferAddress;
    env->jni.GetDirectBufferCapacity = GetDirectBufferCapacity;

    return env;
}
