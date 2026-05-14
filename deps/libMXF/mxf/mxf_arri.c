/*
 * ARRI RDD 54 / RDD 55 data model extensions
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <mxf/mxf.h>
#include <mxf/mxf_macros.h>
#include <mxf/mxf_arri.h>


#define MXF_BASIC_TYPE_DEF(id, name, size) \
    CHK_ORET(mxf_register_basic_type(dataModel, name, id, size) != NULL);

#define MXF_ARRAY_TYPE_DEF(id, name, elementTypeId, fixedSize) \
    CHK_ORET(mxf_register_array_type(dataModel, name, id, elementTypeId, fixedSize) != NULL);

#define MXF_COMPOUND_TYPE_DEF(id, name) \
    CHK_ORET((itemType = mxf_register_compound_type(dataModel, name, id)) != NULL);

#define MXF_COMPOUND_TYPE_MEMBER(name, typeId) \
    CHK_ORET(mxf_register_compound_type_member(itemType, name, typeId));

#define MXF_SET_DEFINITION(parentName, name, label) \
    CHK_ORET(mxf_register_set_def(dataModel, #name, &MXF_SET_K(parentName), &MXF_SET_K(name)));

#define MXF_ITEM_DEFINITION(setName, name, label, tag, typeId, isRequired) \
    CHK_ORET(mxf_register_item_def(dataModel, #name, &MXF_SET_K(setName), &MXF_ITEM_K(setName, name), tag, typeId, isRequired));

int mxf_arri_load_extensions(MXFDataModel *dataModel)
{
    MXFItemType *itemType = NULL;

#include <mxf/mxf_arri_extensions_data_model.h>

    return 1;
}
