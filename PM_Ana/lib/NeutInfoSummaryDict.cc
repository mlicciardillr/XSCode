//
// File generated by rootcint at Mon Mar  3 19:04:22 2014

// Do NOT change. Changes will be lost next time file is generated
//

#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "NeutInfoSummaryDict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void NeutInfoSummary_ShowMembers(void *obj, TMemberInspector &R__insp, char *R__parent);
   static void *new_NeutInfoSummary(void *p = 0);
   static void *newArray_NeutInfoSummary(Long_t size, void *p);
   static void delete_NeutInfoSummary(void *p);
   static void deleteArray_NeutInfoSummary(void *p);
   static void destruct_NeutInfoSummary(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::NeutInfoSummary*)
   {
      ::NeutInfoSummary *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::NeutInfoSummary >(0);
      static ::ROOT::TGenericClassInfo 
         instance("NeutInfoSummary", ::NeutInfoSummary::Class_Version(), "NeutInfoSummary.h", 13,
                  typeid(::NeutInfoSummary), DefineBehavior(ptr, ptr),
                  &::NeutInfoSummary::Dictionary, isa_proxy, 0,
                  sizeof(::NeutInfoSummary) );
      instance.SetNew(&new_NeutInfoSummary);
      instance.SetNewArray(&newArray_NeutInfoSummary);
      instance.SetDelete(&delete_NeutInfoSummary);
      instance.SetDeleteArray(&deleteArray_NeutInfoSummary);
      instance.SetDestructor(&destruct_NeutInfoSummary);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::NeutInfoSummary*)
   {
      return GenerateInitInstanceLocal((::NeutInfoSummary*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::NeutInfoSummary*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *NeutInfoSummary::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *NeutInfoSummary::Class_Name()
{
   return "NeutInfoSummary";
}

//______________________________________________________________________________
const char *NeutInfoSummary::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NeutInfoSummary*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int NeutInfoSummary::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NeutInfoSummary*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void NeutInfoSummary::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NeutInfoSummary*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *NeutInfoSummary::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NeutInfoSummary*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void NeutInfoSummary::Streamer(TBuffer &R__b)
{
   // Stream an object of class NeutInfoSummary.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> Mode;
      R__b >> Numnu;
      R__b.ReadStaticArray((int*)Ipnu);
      R__b.ReadStaticArray((float*)Abspnu);
      R__b.ReadStaticArray((float*)Pnu);
      R__b.CheckByteCount(R__s, R__c, NeutInfoSummary::IsA());
   } else {
      R__c = R__b.WriteVersion(NeutInfoSummary::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << Mode;
      R__b << Numnu;
      R__b.WriteArray(Ipnu, 30);
      R__b.WriteArray(Abspnu, 30);
      R__b.WriteArray((float*)Pnu, 90);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

//______________________________________________________________________________
void NeutInfoSummary::ShowMembers(TMemberInspector &R__insp, char *R__parent)
{
      // Inspect the data members of an object of class NeutInfoSummary.
      TClass *R__cl = ::NeutInfoSummary::IsA();
      Int_t R__ncp = strlen(R__parent);
      if (R__ncp || R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__parent, "Mode", &Mode);
      R__insp.Inspect(R__cl, R__parent, "Numnu", &Numnu);
      R__insp.Inspect(R__cl, R__parent, "Ipnu[30]", Ipnu);
      R__insp.Inspect(R__cl, R__parent, "Abspnu[30]", Abspnu);
      R__insp.Inspect(R__cl, R__parent, "Pnu[30][3]", Pnu);
      TObject::ShowMembers(R__insp, R__parent);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_NeutInfoSummary(void *p) {
      return  p ? new(p) ::NeutInfoSummary : new ::NeutInfoSummary;
   }
   static void *newArray_NeutInfoSummary(Long_t nElements, void *p) {
      return p ? new(p) ::NeutInfoSummary[nElements] : new ::NeutInfoSummary[nElements];
   }
   // Wrapper around operator delete
   static void delete_NeutInfoSummary(void *p) {
      delete ((::NeutInfoSummary*)p);
   }
   static void deleteArray_NeutInfoSummary(void *p) {
      delete [] ((::NeutInfoSummary*)p);
   }
   static void destruct_NeutInfoSummary(void *p) {
      typedef ::NeutInfoSummary current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::NeutInfoSummary

/********************************************************
* NeutInfoSummaryDict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && (__GNUC__ > 3) && (__GNUC_MINOR__ > 1)
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableNeutInfoSummaryDict();

extern "C" void G__set_cpp_environmentNeutInfoSummaryDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("NeutInfoSummary.h");
  G__cpp_reset_tagtableNeutInfoSummaryDict();
}
#include <new>
extern "C" int G__cpp_dllrevNeutInfoSummaryDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* NeutInfoSummary */
static int G__NeutInfoSummaryDict_139_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   NeutInfoSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new NeutInfoSummary[n];
     } else {
       p = new((void*) gvp) NeutInfoSummary[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new NeutInfoSummary;
     } else {
       p = new((void*) gvp) NeutInfoSummary;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   result7->type = 'u';
   result7->tagnum = G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   NeutInfoSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 1
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new NeutInfoSummary(*(NeutInfoSummary*) libp->para[0].ref);
   } else {
     p = new((void*) gvp) NeutInfoSummary(*(NeutInfoSummary*) libp->para[0].ref);
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   result7->type = 'u';
   result7->tagnum = G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) NeutInfoSummary::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) NeutInfoSummary::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) NeutInfoSummary::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      NeutInfoSummary::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((NeutInfoSummary*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) NeutInfoSummary::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) NeutInfoSummary::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) NeutInfoSummary::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__NeutInfoSummaryDict_139_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) NeutInfoSummary::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef NeutInfoSummary G__TNeutInfoSummary;
static int G__NeutInfoSummaryDict_139_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (NeutInfoSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((NeutInfoSummary*) (soff+(sizeof(NeutInfoSummary)*i)))->~G__TNeutInfoSummary();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (NeutInfoSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((NeutInfoSummary*) (soff))->~G__TNeutInfoSummary();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__NeutInfoSummaryDict_139_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   NeutInfoSummary* dest = (NeutInfoSummary*) G__getstructoffset();
   *dest = *(NeutInfoSummary*) libp->para[0].ref;
   const NeutInfoSummary& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* NeutInfoSummary */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncNeutInfoSummaryDict {
 public:
  G__Sizep2memfuncNeutInfoSummaryDict(): p(&G__Sizep2memfuncNeutInfoSummaryDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncNeutInfoSummaryDict::*p)();
};

size_t G__get_sizep2memfuncNeutInfoSummaryDict()
{
  G__Sizep2memfuncNeutInfoSummaryDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceNeutInfoSummaryDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary))) {
     NeutInfoSummary *G__Lderived;
     G__Lderived=(NeutInfoSummary*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary),G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableNeutInfoSummaryDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* NeutInfoSummary */
static void G__setup_memvarNeutInfoSummary(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary));
   { NeutInfoSummary *p; p=(NeutInfoSummary*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->Mode)-(long)(p)),105,0,0,-1,-1,-1,1,"Mode=",0,"Neutrino interaction mode");
   G__memvar_setup((void*)((long)(&p->Numnu)-(long)(p)),105,0,0,-1,-1,-1,1,"Numnu=",0,"# of generated particle");
   G__memvar_setup((void*)((long)(&p->Ipnu)-(long)(p)),105,0,0,-1,-1,-1,1,"Ipnu[30]=",0,"particle id");
   G__memvar_setup((void*)((long)(&p->Abspnu)-(long)(p)),102,0,0,-1,-1,-1,1,"Abspnu[30]=",0,"absolute momentum [MeV]");
   G__memvar_setup((void*)((long)(&p->Pnu)-(long)(p)),102,0,0,-1,-1,-1,1,"Pnu[30][3]=",0,"direction");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarNeutInfoSummaryDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncNeutInfoSummary(void) {
   /* NeutInfoSummary */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary));
   G__memfunc_setup("NeutInfoSummary",1558,G__NeutInfoSummaryDict_139_0_1, 105, G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("NeutInfoSummary",1558,G__NeutInfoSummaryDict_139_0_2, 105, G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary), -1, 0, 1, 1, 1, 0, "u 'NeutInfoSummary' - 11 - neut", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Clear",487,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "C - 'Option_t' 10 '\"\"' option", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Print",525,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 8, "C - 'Option_t' 10 - option", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Class",502,G__NeutInfoSummaryDict_139_0_5, 85, G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (TClass* (*)())(&NeutInfoSummary::Class), 0);
   G__memfunc_setup("Class_Name",982,G__NeutInfoSummaryDict_139_0_6, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&NeutInfoSummary::Class_Name), 0);
   G__memfunc_setup("Class_Version",1339,G__NeutInfoSummaryDict_139_0_7, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (Version_t (*)())(&NeutInfoSummary::Class_Version), 0);
   G__memfunc_setup("Dictionary",1046,G__NeutInfoSummaryDict_139_0_8, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (void (*)())(&NeutInfoSummary::Dictionary), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 2, 1, 1, 0, 
"u 'TMemberInspector' - 1 - insp C - - 0 - parent", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__NeutInfoSummaryDict_139_0_12, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__NeutInfoSummaryDict_139_0_13, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&NeutInfoSummary::DeclFileName), 0);
   G__memfunc_setup("ImplFileLine",1178,G__NeutInfoSummaryDict_139_0_14, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&NeutInfoSummary::ImplFileLine), 0);
   G__memfunc_setup("ImplFileName",1171,G__NeutInfoSummaryDict_139_0_15, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&NeutInfoSummary::ImplFileName), 0);
   G__memfunc_setup("DeclFileLine",1152,G__NeutInfoSummaryDict_139_0_16, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&NeutInfoSummary::DeclFileLine), 0);
   // automatic destructor
   G__memfunc_setup("~NeutInfoSummary", 1684, G__NeutInfoSummaryDict_139_0_17, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__NeutInfoSummaryDict_139_0_18, (int) ('u'), G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary), -1, 1, 1, 1, 1, 0, "u 'NeutInfoSummary' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncNeutInfoSummaryDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalNeutInfoSummaryDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcNeutInfoSummaryDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__NeutInfoSummaryDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__NeutInfoSummaryDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__NeutInfoSummaryDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__NeutInfoSummaryDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__NeutInfoSummaryDictLN_NeutInfoSummary = { "NeutInfoSummary" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableNeutInfoSummaryDict() {
  G__NeutInfoSummaryDictLN_TClass.tagnum = -1 ;
  G__NeutInfoSummaryDictLN_TBuffer.tagnum = -1 ;
  G__NeutInfoSummaryDictLN_TMemberInspector.tagnum = -1 ;
  G__NeutInfoSummaryDictLN_TObject.tagnum = -1 ;
  G__NeutInfoSummaryDictLN_NeutInfoSummary.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableNeutInfoSummaryDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__NeutInfoSummaryDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__NeutInfoSummaryDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__NeutInfoSummaryDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__NeutInfoSummaryDictLN_TObject);
   G__tagtable_setup(G__get_linked_tagnum(&G__NeutInfoSummaryDictLN_NeutInfoSummary),sizeof(NeutInfoSummary),-1,30464,"Neut Info Summary",G__setup_memvarNeutInfoSummary,G__setup_memfuncNeutInfoSummary);
}
extern "C" void G__cpp_setupNeutInfoSummaryDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupNeutInfoSummaryDict()");
  G__set_cpp_environmentNeutInfoSummaryDict();
  G__cpp_setup_tagtableNeutInfoSummaryDict();

  G__cpp_setup_inheritanceNeutInfoSummaryDict();

  G__cpp_setup_typetableNeutInfoSummaryDict();

  G__cpp_setup_memvarNeutInfoSummaryDict();

  G__cpp_setup_memfuncNeutInfoSummaryDict();
  G__cpp_setup_globalNeutInfoSummaryDict();
  G__cpp_setup_funcNeutInfoSummaryDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncNeutInfoSummaryDict();
  return;
}
class G__cpp_setup_initNeutInfoSummaryDict {
  public:
    G__cpp_setup_initNeutInfoSummaryDict() { G__add_setup_func("NeutInfoSummaryDict",(G__incsetup)(&G__cpp_setupNeutInfoSummaryDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initNeutInfoSummaryDict() { G__remove_setup_func("NeutInfoSummaryDict"); }
};
G__cpp_setup_initNeutInfoSummaryDict G__cpp_setup_initializerNeutInfoSummaryDict;

