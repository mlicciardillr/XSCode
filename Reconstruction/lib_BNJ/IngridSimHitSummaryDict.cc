//
// File generated by rootcint at Mon Jul  1 21:35:28 2013

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
#include "IngridSimHitSummaryDict.h"

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
   void IngridSimHitSummary_ShowMembers(void *obj, TMemberInspector &R__insp, char *R__parent);
   static void *new_IngridSimHitSummary(void *p = 0);
   static void *newArray_IngridSimHitSummary(Long_t size, void *p);
   static void delete_IngridSimHitSummary(void *p);
   static void deleteArray_IngridSimHitSummary(void *p);
   static void destruct_IngridSimHitSummary(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IngridSimHitSummary*)
   {
      ::IngridSimHitSummary *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::IngridSimHitSummary >(0);
      static ::ROOT::TGenericClassInfo 
         instance("IngridSimHitSummary", ::IngridSimHitSummary::Class_Version(), "IngridSimHitSummary.h", 10,
                  typeid(::IngridSimHitSummary), DefineBehavior(ptr, ptr),
                  &::IngridSimHitSummary::Dictionary, isa_proxy, 0,
                  sizeof(::IngridSimHitSummary) );
      instance.SetNew(&new_IngridSimHitSummary);
      instance.SetNewArray(&newArray_IngridSimHitSummary);
      instance.SetDelete(&delete_IngridSimHitSummary);
      instance.SetDeleteArray(&deleteArray_IngridSimHitSummary);
      instance.SetDestructor(&destruct_IngridSimHitSummary);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IngridSimHitSummary*)
   {
      return GenerateInitInstanceLocal((::IngridSimHitSummary*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::IngridSimHitSummary*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *IngridSimHitSummary::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *IngridSimHitSummary::Class_Name()
{
   return "IngridSimHitSummary";
}

//______________________________________________________________________________
const char *IngridSimHitSummary::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::IngridSimHitSummary*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int IngridSimHitSummary::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::IngridSimHitSummary*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void IngridSimHitSummary::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::IngridSimHitSummary*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *IngridSimHitSummary::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::IngridSimHitSummary*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void IngridSimHitSummary::Streamer(TBuffer &R__b)
{
   // Stream an object of class IngridSimHitSummary.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> edeposit;
      R__b >> trackid;
      R__b >> pdg;
      R__b.CheckByteCount(R__s, R__c, IngridSimHitSummary::IsA());
   } else {
      R__c = R__b.WriteVersion(IngridSimHitSummary::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << edeposit;
      R__b << trackid;
      R__b << pdg;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

//______________________________________________________________________________
void IngridSimHitSummary::ShowMembers(TMemberInspector &R__insp, char *R__parent)
{
      // Inspect the data members of an object of class IngridSimHitSummary.
      TClass *R__cl = ::IngridSimHitSummary::IsA();
      Int_t R__ncp = strlen(R__parent);
      if (R__ncp || R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__parent, "edeposit", &edeposit);
      R__insp.Inspect(R__cl, R__parent, "trackid", &trackid);
      R__insp.Inspect(R__cl, R__parent, "pdg", &pdg);
      TObject::ShowMembers(R__insp, R__parent);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_IngridSimHitSummary(void *p) {
      return  p ? new(p) ::IngridSimHitSummary : new ::IngridSimHitSummary;
   }
   static void *newArray_IngridSimHitSummary(Long_t nElements, void *p) {
      return p ? new(p) ::IngridSimHitSummary[nElements] : new ::IngridSimHitSummary[nElements];
   }
   // Wrapper around operator delete
   static void delete_IngridSimHitSummary(void *p) {
      delete ((::IngridSimHitSummary*)p);
   }
   static void deleteArray_IngridSimHitSummary(void *p) {
      delete [] ((::IngridSimHitSummary*)p);
   }
   static void destruct_IngridSimHitSummary(void *p) {
      typedef ::IngridSimHitSummary current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::IngridSimHitSummary

/********************************************************
* IngridSimHitSummaryDict.cc
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

extern "C" void G__cpp_reset_tagtableIngridSimHitSummaryDict();

extern "C" void G__set_cpp_environmentIngridSimHitSummaryDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("IngridSimHitSummary.h");
  G__cpp_reset_tagtableIngridSimHitSummaryDict();
}
#include <new>
extern "C" int G__cpp_dllrevIngridSimHitSummaryDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* IngridSimHitSummary */
static int G__IngridSimHitSummaryDict_84_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   IngridSimHitSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new IngridSimHitSummary[n];
     } else {
       p = new((void*) gvp) IngridSimHitSummary[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new IngridSimHitSummary;
     } else {
       p = new((void*) gvp) IngridSimHitSummary;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   result7->type = 'u';
   result7->tagnum = G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((IngridSimHitSummary*) G__getstructoffset())->Print();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) IngridSimHitSummary::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) IngridSimHitSummary::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) IngridSimHitSummary::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      IngridSimHitSummary::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((IngridSimHitSummary*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) IngridSimHitSummary::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) IngridSimHitSummary::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) IngridSimHitSummary::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridSimHitSummaryDict_84_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) IngridSimHitSummary::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__IngridSimHitSummaryDict_84_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   IngridSimHitSummary* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new IngridSimHitSummary(*(IngridSimHitSummary*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   result7->type = 'u';
   result7->tagnum = G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef IngridSimHitSummary G__TIngridSimHitSummary;
static int G__IngridSimHitSummaryDict_84_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
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
       delete[] (IngridSimHitSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((IngridSimHitSummary*) (soff+(sizeof(IngridSimHitSummary)*i)))->~G__TIngridSimHitSummary();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (IngridSimHitSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((IngridSimHitSummary*) (soff))->~G__TIngridSimHitSummary();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__IngridSimHitSummaryDict_84_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   IngridSimHitSummary* dest = (IngridSimHitSummary*) G__getstructoffset();
   *dest = *(IngridSimHitSummary*) libp->para[0].ref;
   const IngridSimHitSummary& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* IngridSimHitSummary */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncIngridSimHitSummaryDict {
 public:
  G__Sizep2memfuncIngridSimHitSummaryDict(): p(&G__Sizep2memfuncIngridSimHitSummaryDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncIngridSimHitSummaryDict::*p)();
};

size_t G__get_sizep2memfuncIngridSimHitSummaryDict()
{
  G__Sizep2memfuncIngridSimHitSummaryDict a;
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
extern "C" void G__cpp_setup_inheritanceIngridSimHitSummaryDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary))) {
     IngridSimHitSummary *G__Lderived;
     G__Lderived=(IngridSimHitSummary*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary),G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableIngridSimHitSummaryDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* IngridSimHitSummary */
static void G__setup_memvarIngridSimHitSummary(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary));
   { IngridSimHitSummary *p; p=(IngridSimHitSummary*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->edeposit)-(long)(p)),102,0,0,-1,-1,-1,1,"edeposit=",0,"Energy deposit (MeV)");
   G__memvar_setup((void*)((long)(&p->trackid)-(long)(p)),105,0,0,-1,-1,-1,1,"trackid=",0,"ID of GEANT4 track responsible for hit");
   G__memvar_setup((void*)((long)(&p->pdg)-(long)(p)),105,0,0,-1,-1,-1,1,"pdg=",0,"PDG particle ID of GEANT4 track responsible for hit");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarIngridSimHitSummaryDict() {
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
static void G__setup_memfuncIngridSimHitSummary(void) {
   /* IngridSimHitSummary */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary));
   G__memfunc_setup("IngridSimHitSummary",1945,G__IngridSimHitSummaryDict_84_0_1, 105, G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Clear",487,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "C - 'Option_t' 10 '\"\"' option", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Print",525,G__IngridSimHitSummaryDict_84_0_3, 121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__IngridSimHitSummaryDict_84_0_4, 85, G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (TClass* (*)())(&IngridSimHitSummary::Class), 0);
   G__memfunc_setup("Class_Name",982,G__IngridSimHitSummaryDict_84_0_5, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&IngridSimHitSummary::Class_Name), 0);
   G__memfunc_setup("Class_Version",1339,G__IngridSimHitSummaryDict_84_0_6, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (Version_t (*)())(&IngridSimHitSummary::Class_Version), 0);
   G__memfunc_setup("Dictionary",1046,G__IngridSimHitSummaryDict_84_0_7, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (void (*)())(&IngridSimHitSummary::Dictionary), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 2, 1, 1, 0, 
"u 'TMemberInspector' - 1 - insp C - - 0 - parent", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__IngridSimHitSummaryDict_84_0_11, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__IngridSimHitSummaryDict_84_0_12, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&IngridSimHitSummary::DeclFileName), 0);
   G__memfunc_setup("ImplFileLine",1178,G__IngridSimHitSummaryDict_84_0_13, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&IngridSimHitSummary::ImplFileLine), 0);
   G__memfunc_setup("ImplFileName",1171,G__IngridSimHitSummaryDict_84_0_14, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&IngridSimHitSummary::ImplFileName), 0);
   G__memfunc_setup("DeclFileLine",1152,G__IngridSimHitSummaryDict_84_0_15, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&IngridSimHitSummary::DeclFileLine), 0);
   // automatic copy constructor
   G__memfunc_setup("IngridSimHitSummary", 1945, G__IngridSimHitSummaryDict_84_0_16, (int) ('i'), G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary), -1, 0, 1, 1, 1, 0, "u 'IngridSimHitSummary' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~IngridSimHitSummary", 2071, G__IngridSimHitSummaryDict_84_0_17, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__IngridSimHitSummaryDict_84_0_18, (int) ('u'), G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary), -1, 1, 1, 1, 1, 0, "u 'IngridSimHitSummary' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncIngridSimHitSummaryDict() {
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
extern "C" void G__cpp_setup_globalIngridSimHitSummaryDict() {
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

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcIngridSimHitSummaryDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__IngridSimHitSummaryDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__IngridSimHitSummaryDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__IngridSimHitSummaryDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__IngridSimHitSummaryDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__IngridSimHitSummaryDictLN_IngridSimHitSummary = { "IngridSimHitSummary" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableIngridSimHitSummaryDict() {
  G__IngridSimHitSummaryDictLN_TClass.tagnum = -1 ;
  G__IngridSimHitSummaryDictLN_TBuffer.tagnum = -1 ;
  G__IngridSimHitSummaryDictLN_TMemberInspector.tagnum = -1 ;
  G__IngridSimHitSummaryDictLN_TObject.tagnum = -1 ;
  G__IngridSimHitSummaryDictLN_IngridSimHitSummary.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableIngridSimHitSummaryDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__IngridSimHitSummaryDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__IngridSimHitSummaryDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__IngridSimHitSummaryDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__IngridSimHitSummaryDictLN_TObject);
   G__tagtable_setup(G__get_linked_tagnum(&G__IngridSimHitSummaryDictLN_IngridSimHitSummary),sizeof(IngridSimHitSummary),-1,29952,"Ingrid Hit Sim Summary",G__setup_memvarIngridSimHitSummary,G__setup_memfuncIngridSimHitSummary);
}
extern "C" void G__cpp_setupIngridSimHitSummaryDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupIngridSimHitSummaryDict()");
  G__set_cpp_environmentIngridSimHitSummaryDict();
  G__cpp_setup_tagtableIngridSimHitSummaryDict();

  G__cpp_setup_inheritanceIngridSimHitSummaryDict();

  G__cpp_setup_typetableIngridSimHitSummaryDict();

  G__cpp_setup_memvarIngridSimHitSummaryDict();

  G__cpp_setup_memfuncIngridSimHitSummaryDict();
  G__cpp_setup_globalIngridSimHitSummaryDict();
  G__cpp_setup_funcIngridSimHitSummaryDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncIngridSimHitSummaryDict();
  return;
}
class G__cpp_setup_initIngridSimHitSummaryDict {
  public:
    G__cpp_setup_initIngridSimHitSummaryDict() { G__add_setup_func("IngridSimHitSummaryDict",(G__incsetup)(&G__cpp_setupIngridSimHitSummaryDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initIngridSimHitSummaryDict() { G__remove_setup_func("IngridSimHitSummaryDict"); }
};
G__cpp_setup_initIngridSimHitSummaryDict G__cpp_setup_initializerIngridSimHitSummaryDict;

