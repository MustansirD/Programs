
#define for_each_bio(_bio)              \
        for (; _bio; _bio = _bio->bi_next)
#define __rq_for_each_bio(_bio, rq)     \
        if ((rq->bio))                  \
                for (_bio = (rq)->bio; _bio; _bio = _bio->bi_next)

#define rq_for_each_segment(bvl, _rq, _iter)                    \
        __rq_for_each_bio(_iter.bio, _rq)                       \
                bio_for_each_segment(bvl, _iter.bio, _iter.iter)

#define rq_iter_last(bvec, _iter)                               \
                (_iter.bio->bi_next == NULL &&                  \
                 bio_iter_last(bvec, _iter.iter))

#define __bio_for_each_segment(bvl, bio, iter, start)                   \
        for (iter = (start);                                            \
             (iter).bi_size &&                                          \
                ((bvl = bio_iter_iovec((bio), (iter))), 1);             \
             bio_advance_iter((bio), &(iter), (bvl).bv_len))

#define bio_for_each_segment(bvl, bio, iter)                            \
        __bio_for_each_segment(bvl, bio, iter, (bio)->bi_iter)

#define bio_iter_last(bvec, iter) ((iter).bi_size == (bvec).bv_len)


//-------------------------------------------------------------------

#define __bvec_iter_bvec(bvec, iter)    (&(bvec)[(iter).bi_idx])

#define bvec_iter_page(bvec, iter)                              \
        (__bvec_iter_bvec((bvec), (iter))->bv_page)

#define bvec_iter_len(bvec, iter)                               \
        min((iter).bi_size,                                     \
            __bvec_iter_bvec((bvec), (iter))->bv_len - (iter).bi_bvec_done)

#define bvec_iter_offset(bvec, iter)                            \
        (__bvec_iter_bvec((bvec), (iter))->bv_offset + (iter).bi_bvec_done)

#define bvec_iter_bvec(bvec, iter)                              \
((struct bio_vec) {                                             \
        .bv_page        = bvec_iter_page((bvec), (iter)),       \
        .bv_len         = bvec_iter_len((bvec), (iter)),        \
        .bv_offset      = bvec_iter_offset((bvec), (iter)),     \
})

#define bio_iter_iovec(bio, iter)                               \
        bvec_iter_bvec((bio)->bi_io_vec, (iter))

#define bio_iter_page(bio, iter)                                \
        bvec_iter_page((bio)->bi_io_vec, (iter))
#define bio_iter_len(bio, iter)                                 \
        bvec_iter_len((bio)->bi_io_vec, (iter))
#define bio_iter_offset(bio, iter)                              \
        bvec_iter_offset((bio)->bi_io_vec, (iter))

#define bio_page(bio)           bio_iter_page((bio), (bio)->bi_iter)
#define bio_offset(bio)         bio_iter_offset((bio), (bio)->bi_iter)
#define bio_iovec(bio)          bio_iter_iovec((bio), (bio)->bi_iter)

#define bio_multiple_segments(bio)                              \
        ((bio)->bi_iter.bi_size != bio_iovec(bio).bv_len)
#define bio_sectors(bio)        ((bio)->bi_iter.bi_size >> 9)
#define bio_end_sector(bio)     ((bio)->bi_iter.bi_sector + bio_sectors((bio)))




//-------------------------------------------------------------------











struct bio_vec *bv;
struct req_iterator iter;
struct request *req;

rq_for_each_segment(bv,req,iter){
}

