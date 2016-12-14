//
// File generated by rootcint at Sun Aug 30 12:02:51 2015

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
#include "IngridHitSummaryDict.h"

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
   void IngridHitSummary_ShowMembers(void *obj, TMemberInspector &R__insp, char *R__parent);
   static void *new_IngridHitSummary(void *p = 0);
   static void *newArray_IngridHitSummary(Long_t size, void *p);
   static void delete_IngridHitSummary(void *p);
   static void deleteArray_IngridHitSummary(void *p);
   static void destruct_IngridHitSummary(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IngridHitSummary*)
   {
      ::IngridHitSummary *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::IngridHitSummary >(0);
      static ::ROOT::TGenericClassInfo 
         instance("IngridHitSummary", ::IngridHitSummary::Class_Version(), "IngridHitSummary.h", 16,
                  typeid(::IngridHitSummary), DefineBehavior(ptr, ptr),
                  &::IngridHitSummary::Dictionary, isa_proxy, 0,
                  sizeof(::IngridHitSummary) );
      instance.SetNew(&new_IngridHitSummary);
      instance.SetNewArray(&newArray_IngridHitSummary);
      instance.SetDelete(&delete_IngridHitSummary);
      instance.SetDeleteArray(&deleteArray_IngridHitSummary);
      instance.SetDestructor(&destruct_IngridHitSummary);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IngridHitSummary*)
   {
      return GenerateInitInstanceLocal((::IngridHitSummary*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::IngridHitSummary*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *IngridHitSummary::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *IngridHitSummary::Class_Name()
{
   return "IngridHitSummary";
}

//______________________________________________________________________________
const char *IngridHitSummary::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::IngridHitSummary*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int IngridHitSummary::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::IngridHitSummary*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void IngridHitSummary::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::IngridHitSummary*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *IngridHitSummary::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::IngridHitSummary*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void IngridHitSummary::Streamer(TBuffer &R__b)
{
   // Stream an object of class IngridHitSummary.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> mod;
      R__b >> cyc;
      R__b >> view;
      R__b >> pln;
      R__b >> ch;
      R__b >> adc;
      R__b >> loadc;
      R__b >> pe;
      R__b >> lope;
      R__b >> pecorr;
      R__b >> vise;
      R__b >> visecorr;
      R__b >> tdc;
      R__b >> time;
      R__b >> tnearhit;
      R__b >> timecorr;
      R__b >> xy;
      R__b >> z;
      R__b >> addbasicrecon;
      R__b >> dummy;
      R__b >> gocosmic;
      R__b >> hitcosmic;
      R__b >> isohit;
      R__b >> nsimhits;
      int R__i;
      for (R__i = 0; R__i < 1; R__i++)
         fIngridSimHit[R__i].Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, IngridHitSummary::IsA());
   } else {
      R__c = R__b.WriteVersion(IngridHitSummary::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << mod;
      R__b << cyc;
      R__b << view;
      R__b << pln;
      R__b << ch;
      R__b << adc;
      R__b << loadc;
      R__b << pe;
      R__b << lope;
      R__b << pecorr;
      R__b << vise;
      R__b << visecorr;
      R__b << tdc;
      R__b << time;
      R__b << tnearhit;
      R__b << timecorr;
      R__b << xy;
      R__b << z;
      R__b << addbasicrecon;
      R__b << dummy;
      R__b << gocosmic;
      R__b << hitcosmic;
      R__b << isohit;
      R__b << nsimhits;
      int R__i;
      for (R__i = 0; R__i < 1; R__i++)
         fIngridSimHit[R__i].Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

//______________________________________________________________________________
void IngridHitSummary::ShowMembers(TMemberInspector &R__insp, char *R__parent)
{
      // Inspect the data members of an object of class IngridHitSummary.
      TClass *R__cl = ::IngridHitSummary::IsA();
      Int_t R__ncp = strlen(R__parent);
      if (R__ncp || R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__parent, "mod", &mod);
      R__insp.Inspect(R__cl, R__parent, "cyc", &cyc);
      R__insp.Inspect(R__cl, R__parent, "view", &view);
      R__insp.Inspect(R__cl, R__parent, "pln", &pln);
      R__insp.Inspect(R__cl, R__parent, "ch", &ch);
      R__insp.Inspect(R__cl, R__parent, "adc", &adc);
      R__insp.Inspect(R__cl, R__parent, "loadc", &loadc);
      R__insp.Inspect(R__cl, R__parent, "pe", &pe);
      R__insp.Inspect(R__cl, R__parent, "lope", &lope);
      R__insp.Inspect(R__cl, R__parent, "pecorr", &pecorr);
      R__insp.Inspect(R__cl, R__parent, "vise", &vise);
      R__insp.Inspect(R__cl, R__parent, "visecorr", &visecorr);
      R__insp.Inspect(R__cl, R__parent, "tdc", &tdc);
      R__insp.Inspect(R__cl, R__parent, "time", &time);
      R__insp.Inspect(R__cl, R__parent, "tnearhit", &tnearhit);
      R__insp.Inspect(R__cl, R__parent, "timecorr", &timecorr);
      R__insp.Inspect(R__cl, R__parent, "xy", &xy);
      R__insp.Inspect(R__cl, R__parent, "z", &z);
      R__insp.Inspect(R__cl, R__parent, "addbasicrecon", &addbasicrecon);
      R__insp.Inspect(R__cl, R__parent, "dummy", &dummy);
      R__insp.Inspect(R__cl, R__parent, "gocosmic", &gocosmic);
      R__insp.Inspect(R__cl, R__parent, "hitcosmic", &hitcosmic);
      R__insp.Inspect(R__cl, R__parent, "isohit", &isohit);
      R__insp.Inspect(R__cl, R__parent, "nsimhits", &nsimhits);
      R__insp.Inspect(R__cl, R__parent, "fIngridSimHit[1]", fIngridSimHit);
      TObject::ShowMembers(R__insp, R__parent);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_IngridHitSummary(void *p) {
      return  p ? new(p) ::IngridHitSummary : new ::IngridHitSummary;
   }
   static void *newArray_IngridHitSummary(Long_t nElements, void *p) {
      return p ? new(p) ::IngridHitSummary[nElements] : new ::IngridHitSummary[nElements];
   }
   // Wrapper around operator delete
   static void delete_IngridHitSummary(void *p) {
      delete ((::IngridHitSummary*)p);
   }
   static void deleteArray_IngridHitSummary(void *p) {
      delete [] ((::IngridHitSummary*)p);
   }
   static void destruct_IngridHitSummary(void *p) {
      typedef ::IngridHitSummary current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::IngridHitSummary

/********************************************************
* IngridHitSummaryDict.cc
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

extern "C" void G__cpp_reset_tagtableIngridHitSummaryDict();

extern "C" void G__set_cpp_environmentIngridHitSummaryDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("IngridHitSummary.h");
  G__cpp_reset_tagtableIngridHitSummaryDict();
}
#include <new>
extern "C" int G__cpp_dllrevIngridHitSummaryDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* IngridHitSummary */
static int G__IngridHitSummaryDict_174_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   IngridHitSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new IngridHitSummary[n];
     } else {
       p = new((void*) gvp) IngridHitSummary[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new IngridHitSummary;
     } else {
       p = new((void*) gvp) IngridHitSummary;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   IngridHitSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 1
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new IngridHitSummary(*(IngridHitSummary*) libp->para[0].ref);
   } else {
     p = new((void*) gvp) IngridHitSummary(*(IngridHitSummary*) libp->para[0].ref);
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((IngridHitSummary*) G__getstructoffset())->Print();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 102, (double) ((IngridHitSummary*) G__getstructoffset())->Pe());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((const IngridHitSummary*) G__getstructoffset())->NSimHits());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((IngridHitSummary*) G__getstructoffset())->AddIngridSimHit((IngridSimHitSummary*) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) ((const IngridHitSummary*) G__getstructoffset())->GetIngridSimHit((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) IngridHitSummary::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) IngridHitSummary::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) IngridHitSummary::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      IngridHitSummary::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((IngridHitSummary*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) IngridHitSummary::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) IngridHitSummary::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_19(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) IngridHitSummary::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__IngridHitSummaryDict_174_0_20(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) IngridHitSummary::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef IngridHitSummary G__TIngridHitSummary;
static int G__IngridHitSummaryDict_174_0_21(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
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
       delete[] (IngridHitSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((IngridHitSummary*) (soff+(sizeof(IngridHitSummary)*i)))->~G__TIngridHitSummary();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (IngridHitSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((IngridHitSummary*) (soff))->~G__TIngridHitSummary();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__IngridHitSummaryDict_174_0_22(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   IngridHitSummary* dest = (IngridHitSummary*) G__getstructoffset();
   *dest = *(IngridHitSummary*) libp->para[0].ref;
   const IngridHitSummary& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* IngridHitSummary */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncIngridHitSummaryDict {
 public:
  G__Sizep2memfuncIngridHitSummaryDict(): p(&G__Sizep2memfuncIngridHitSummaryDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncIngridHitSummaryDict::*p)();
};

size_t G__get_sizep2memfuncIngridHitSummaryDict()
{
  G__Sizep2memfuncIngridHitSummaryDict a;
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
extern "C" void G__cpp_setup_inheritanceIngridHitSummaryDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary))) {
     IngridHitSummary *G__Lderived;
     G__Lderived=(IngridHitSummary*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary),G__get_linked_tagnum(&G__IngridHitSummaryDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableIngridHitSummaryDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<TSchemaHelper>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<std::bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long,const TObject**>",117,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* IngridHitSummary */
static void G__setup_memvarIngridHitSummary(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary));
   { IngridHitSummary *p; p=(IngridHitSummary*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->mod)-(long)(p)),105,0,0,-1,-1,-1,1,"mod=",0,"Module ID");
   G__memvar_setup((void*)((long)(&p->cyc)-(long)(p)),105,0,0,-1,-1,-1,1,"cyc=",0,"Integration number 0~22");
   G__memvar_setup((void*)((long)(&p->view)-(long)(p)),105,0,0,-1,-1,-1,1,"view=",0,"xz view (0), yz view (1)");
   G__memvar_setup((void*)((long)(&p->pln)-(long)(p)),105,0,0,-1,-1,-1,1,"pln=",0,"plane number");
   G__memvar_setup((void*)((long)(&p->ch)-(long)(p)),105,0,0,-1,-1,-1,1,"ch=",0,"strip number(0~23)");
   G__memvar_setup((void*)((long)(&p->adc)-(long)(p)),105,0,0,-1,-1,-1,1,"adc=",0,"high gain ADC value");
   G__memvar_setup((void*)((long)(&p->loadc)-(long)(p)),105,0,0,-1,-1,-1,1,"loadc=",0,"low  gain ADC value");
   G__memvar_setup((void*)((long)(&p->pe)-(long)(p)),102,0,0,-1,-1,-1,1,"pe=",0,"number of photoelectrons, without correction");
   G__memvar_setup((void*)((long)(&p->lope)-(long)(p)),102,0,0,-1,-1,-1,1,"lope=",0,"number of photoelectrons, without correction");
   G__memvar_setup((void*)((long)(&p->pecorr)-(long)(p)),102,0,0,-1,-1,-1,1,"pecorr=",0,"number of photoelectrons, with correction");
   G__memvar_setup((void*)((long)(&p->vise)-(long)(p)),102,0,0,-1,-1,-1,1,"vise=",0,"visible energy (MeV), without correction");
   G__memvar_setup((void*)((long)(&p->visecorr)-(long)(p)),102,0,0,-1,-1,-1,1,"visecorr=",0,"visible energy (MeV), with correction");
   G__memvar_setup((void*)((long)(&p->tdc)-(long)(p)),108,0,0,-1,-1,-1,1,"tdc=",0,"raw TDC value");
   G__memvar_setup((void*)((long)(&p->time)-(long)(p)),102,0,0,-1,-1,-1,1,"time=",0,"hit time (ns).");
   G__memvar_setup((void*)((long)(&p->tnearhit)-(long)(p)),102,0,0,-1,-1,-1,1,"tnearhit=",0,"minumum value of hit time difference (ns).");
   G__memvar_setup((void*)((long)(&p->timecorr)-(long)(p)),102,0,0,-1,-1,-1,1,"timecorr=",0,"hit time (ns). Only the first hit inside ");
   G__memvar_setup((void*)((long)(&p->xy)-(long)(p)),102,0,0,-1,-1,-1,1,"xy=",0,"transverse position (cm), x or y");
   G__memvar_setup((void*)((long)(&p->z)-(long)(p)),102,0,0,-1,-1,-1,1,"z=",0,"position (cm) along beam direction");
   G__memvar_setup((void*)((long)(&p->addbasicrecon)-(long)(p)),105,0,0,-1,-1,-1,1,"addbasicrecon=",0,"This hit is member of basic recon or not");
   G__memvar_setup((void*)((long)(&p->dummy)-(long)(p)),105,0,0,-1,-1,-1,1,"dummy=",0,"this is dummy(study for MPPC noise)");
   G__memvar_setup((void*)((long)(&p->gocosmic)-(long)(p)),103,0,0,-1,-1,-1,1,"gocosmic=",0,"For efficiency study with cosmic, it is denominator for efficiency");
   G__memvar_setup((void*)((long)(&p->hitcosmic)-(long)(p)),103,0,0,-1,-1,-1,1,"hitcosmic=",0,"For efficiency study with cosmic, it is numerator for efficiency");
   G__memvar_setup((void*)((long)(&p->isohit)-(long)(p)),103,0,0,-1,-1,-1,1,"isohit=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"nsimhits=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_TRef),-1,-1,4,"fIngridSimHit[1]=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__IngridHitSummaryDictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarIngridHitSummaryDict() {
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
static void G__setup_memfuncIngridHitSummary(void) {
   /* IngridHitSummary */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary));
   G__memfunc_setup("IngridHitSummary",1648,G__IngridHitSummaryDict_174_0_1, 105, G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("IngridHitSummary",1648,G__IngridHitSummaryDict_174_0_2, 105, G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary), -1, 0, 1, 1, 1, 0, "u 'IngridHitSummary' - 11 - hit", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Clear",487,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "C - 'Option_t' 10 '\"\"' option", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Print",525,G__IngridHitSummaryDict_174_0_4, 121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Pe",181,G__IngridHitSummaryDict_174_0_5, 102, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("NSimHits",783,G__IngridHitSummaryDict_174_0_6, 105, -1, -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("AddIngridSimHit",1460,G__IngridHitSummaryDict_174_0_7, 121, -1, -1, 0, 1, 1, 1, 0, "U 'IngridSimHitSummary' - 0 - hit", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetIngridSimHit",1483,G__IngridHitSummaryDict_174_0_8, 85, G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridSimHitSummary), -1, 0, 1, 1, 1, 8, "i - - 0 - i", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__IngridHitSummaryDict_174_0_9, 85, G__get_linked_tagnum(&G__IngridHitSummaryDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (TClass* (*)())(&IngridHitSummary::Class), 0);
   G__memfunc_setup("Class_Name",982,G__IngridHitSummaryDict_174_0_10, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&IngridHitSummary::Class_Name), 0);
   G__memfunc_setup("Class_Version",1339,G__IngridHitSummaryDict_174_0_11, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (Version_t (*)())(&IngridHitSummary::Class_Version), 0);
   G__memfunc_setup("Dictionary",1046,G__IngridHitSummaryDict_174_0_12, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (void (*)())(&IngridHitSummary::Dictionary), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__IngridHitSummaryDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 2, 1, 1, 0, 
"u 'TMemberInspector' - 1 - insp C - - 0 - parent", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__IngridHitSummaryDict_174_0_16, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__IngridHitSummaryDict_174_0_17, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&IngridHitSummary::DeclFileName), 0);
   G__memfunc_setup("ImplFileLine",1178,G__IngridHitSummaryDict_174_0_18, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&IngridHitSummary::ImplFileLine), 0);
   G__memfunc_setup("ImplFileName",1171,G__IngridHitSummaryDict_174_0_19, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&IngridHitSummary::ImplFileName), 0);
   G__memfunc_setup("DeclFileLine",1152,G__IngridHitSummaryDict_174_0_20, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&IngridHitSummary::DeclFileLine), 0);
   // automatic destructor
   G__memfunc_setup("~IngridHitSummary", 1774, G__IngridHitSummaryDict_174_0_21, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__IngridHitSummaryDict_174_0_22, (int) ('u'), G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary), -1, 1, 1, 1, 1, 0, "u 'IngridHitSummary' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncIngridHitSummaryDict() {
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
extern "C" void G__cpp_setup_globalIngridHitSummaryDict() {
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
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcIngridHitSummaryDict() {
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
  G__cpp_setup_func10();
  G__cpp_setup_func11();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__IngridHitSummaryDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR = { "iterator<bidirectional_iterator_tag,TObject*,long,const TObject**,const TObject*&>" , 115 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_TRef = { "TRef" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_IngridSimHitSummary = { "IngridSimHitSummary" , 99 , -1 };
G__linked_taginfo G__IngridHitSummaryDictLN_IngridHitSummary = { "IngridHitSummary" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableIngridHitSummaryDict() {
  G__IngridHitSummaryDictLN_TClass.tagnum = -1 ;
  G__IngridHitSummaryDictLN_TBuffer.tagnum = -1 ;
  G__IngridHitSummaryDictLN_TMemberInspector.tagnum = -1 ;
  G__IngridHitSummaryDictLN_TObject.tagnum = -1 ;
  G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__IngridHitSummaryDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR.tagnum = -1 ;
  G__IngridHitSummaryDictLN_TRef.tagnum = -1 ;
  G__IngridHitSummaryDictLN_IngridSimHitSummary.tagnum = -1 ;
  G__IngridHitSummaryDictLN_IngridHitSummary.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableIngridHitSummaryDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_TRef);
   G__get_linked_tagnum_fwd(&G__IngridHitSummaryDictLN_IngridSimHitSummary);
   G__tagtable_setup(G__get_linked_tagnum(&G__IngridHitSummaryDictLN_IngridHitSummary),sizeof(IngridHitSummary),-1,30464,"Ingrid Hit Summary",G__setup_memvarIngridHitSummary,G__setup_memfuncIngridHitSummary);
}
extern "C" void G__cpp_setupIngridHitSummaryDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupIngridHitSummaryDict()");
  G__set_cpp_environmentIngridHitSummaryDict();
  G__cpp_setup_tagtableIngridHitSummaryDict();

  G__cpp_setup_inheritanceIngridHitSummaryDict();

  G__cpp_setup_typetableIngridHitSummaryDict();

  G__cpp_setup_memvarIngridHitSummaryDict();

  G__cpp_setup_memfuncIngridHitSummaryDict();
  G__cpp_setup_globalIngridHitSummaryDict();
  G__cpp_setup_funcIngridHitSummaryDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncIngridHitSummaryDict();
  return;
}
class G__cpp_setup_initIngridHitSummaryDict {
  public:
    G__cpp_setup_initIngridHitSummaryDict() { G__add_setup_func("IngridHitSummaryDict",(G__incsetup)(&G__cpp_setupIngridHitSummaryDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initIngridHitSummaryDict() { G__remove_setup_func("IngridHitSummaryDict"); }
};
G__cpp_setup_initIngridHitSummaryDict G__cpp_setup_initializerIngridHitSummaryDict;

